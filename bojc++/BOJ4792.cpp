#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

inline int find_node(int* nodes, int node)
{
    return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
    nodes[node0] += nodes[node1];
    nodes[node1] = node0;
}

tuple<char, int, int> edges[1 << 20];
int nodes[2000];

int main()
{
    FASTIO();

    int n, m, k;
    while (cin >> n >> m >> k && n > 0)
    {
        for (int i = 0; i < m; ++i)
            cin >> get<0>(edges[i]) >> get<1>(edges[i]) >> get<2>(edges[i]);

        sort(edges, edges + m);
        memset(nodes, -1, sizeof(nodes));

        int vmin = 0;
        int vmax = 0;
        for (int i = 0; i < m; ++i)
        {
            auto ef = edges[i];
            auto eb = edges[m - i - 1];

            int pa = find_node(nodes, get<1>(ef));
            int pb = find_node(nodes, get<2>(ef));

            if (pa != pb)
            {
                if (get<0>(ef) == 'B')
                    vmax++;
                union_node(nodes, pa, pb);
            }

            pa = find_node(nodes + 1000, get<1>(eb));
            pb = find_node(nodes + 1000, get<2>(eb));

            if (pa != pb)
            {
                if (get<0>(eb) == 'B')
                    vmin++;
                union_node(nodes + 1000, pa, pb);
            }
        }

        cout << (k >= vmin && k <= vmax) << '\n';
    }
}