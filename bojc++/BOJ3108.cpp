#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

inline int orientation(const int ax, const int ay, const int bx, const int by, const int cx, const int cy)
{
    int result = (by - ay) * (cx - bx) - (bx - ax) * (cy - by);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

inline int find_node(int* nodes, int node)
{
    return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
    nodes[node0] += nodes[node1];
    nodes[node1] = node0;
}

int rect[1000][4];
int nodes[1000];

int main()
{
    FASTIO();

    int n;
    cin >> n;
    for (int i = 0; i < n * 4; ++i)
        cin >> rect[i / 4][i % 4];

    int r = n;
    bool flag = false;
    memset(nodes, -1, sizeof(nodes));

    for (int i = 0; i < n; ++i)
    {
        if (!(rect[i][0] && rect[i][2] || rect[i][1] > 0 || rect[i][3] < 0))
            flag |= true;
        if (!(rect[i][1] && rect[i][3] || rect[i][0] > 0 || rect[i][2] < 0))
            flag |= true;

        for (int j = i + 1; j < n; ++j)
        {
            if (rect[i][0] > rect[j][2] || rect[i][2] < rect[j][0])
                continue;
            if (rect[i][1] > rect[j][3] || rect[i][3] < rect[j][1])
                continue;

            int o1 = orientation(rect[i][0], rect[i][1], rect[i][2], rect[i][1], rect[j][2], rect[j][1]);
            int o2 = orientation(rect[i][2], rect[i][1], rect[i][2], rect[i][3], rect[j][2], rect[j][3]);
            int o3 = orientation(rect[i][2], rect[i][3], rect[i][0], rect[i][3], rect[j][0], rect[j][3]);
            int o4 = orientation(rect[i][0], rect[i][3], rect[i][0], rect[i][1], rect[j][0], rect[j][1]);

            if ((o1 || o2 || o3 || o4) && abs(o1 + o2 + o3 + o4) == 4)
                continue;

            int pi = find_node(nodes, i);
            int pj = find_node(nodes, j);

            if (pi == pj)
                continue;

            union_node(nodes, pi, pj);
            --r;
        }
    }

    cout << r - flag;
}