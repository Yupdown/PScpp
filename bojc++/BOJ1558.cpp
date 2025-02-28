#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

struct vector2d
{
    int x;
    int y;
};

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

bool intersect(vector2d p1, vector2d p2, vector2d p3, vector2d p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (!(o1 || o2 || o3 || o4))
    {
        int x1, x2, x3, x4;
        if (p1.x == p2.x && p3.x == p4.x && p1.x == p3.x)
        {
            x1 = p1.y;
            x2 = p2.y;
            x3 = p3.y;
            x4 = p4.y;
        }
        else
        {
            x1 = p1.x;
            x2 = p2.x;
            x3 = p3.x;
            x4 = p4.x;
        }

        return max(abs(min(x1, x2) - max(x3, x4)), abs(min(x3, x4) - max(x1, x2))) <= abs(x1 - x2) + abs(x3 - x4);
    }

    return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

int find_node(int* nodes, int node)
{
    return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

void union_node(int* nodes, int node0, int node1)
{
    nodes[node0] += nodes[node1];
    nodes[node1] = node0;
}

int nodes[500000];
pair<vector2d, vector2d> line[500000];

int main()
{
    FASTIO();

    int t;
    cin >> t;

    int c = 0;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        vector2d lv;
        int c0 = c;
        for (int j = 0; j < n; ++j)
        {
            vector2d v;
            cin >> v.x >> v.y;

            if (j > 0)
            {
                nodes[c] = c0;
                line[c] = make_pair(lv, v);
            }
            else
            {
                nodes[c] = -1;
                line[c] = make_pair(v, v);
            }

            lv = v;
            ++c;
        }
    }

    for (int i = 0; i < c; ++i)
    {
        for (int j = i + 1; j < c; ++j)
        {
            int pi = find_node(nodes, i);
            int pj = find_node(nodes, j);

            if (pi == pj)
                continue;

            if (intersect(line[i].first, line[i].second, line[j].first, line[j].second))
            {
                union_node(nodes, pi, pj);
                --t;
            }
        }
    }

    cout << t << endl;
    return 0;
}