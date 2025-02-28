#include <iostream>
#include <math.h>

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

    if ((!o1 && !o2) || (!o3 && !o4))
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

int main()
{
    int n;
    cin >> n;

    pair<vector2d, vector2d> segments[3000];

    for (int i = 0; i < n; i++)
        cin >> segments[i].first.x >> segments[i].first.y >> segments[i].second.x >> segments[i].second.y;

    int nodes[3000];
    for (int i = 0; i < n; i++)
        nodes[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (intersect(segments[i].first, segments[i].second, segments[j].first, segments[j].second))
            {
                int root0 = find_node(nodes, i);
                int root1 = find_node(nodes, j);

                if (root0 == root1)
                    continue;

                union_node(nodes, root0, root1);
            }
        }
    }

    int result1 = 0;
    int result2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nodes[i] < 0)
        {
            result1 += 1;
            result2 = max(result2, -nodes[i]);
        }
    }

    cout << result1 << endl << result2 << endl;
    return 0;
}