#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

vector<array<int, 3>> table;
int nodes[200000];

inline int find_node(int* nodes, int node)
{
    return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
    nodes[node0] += nodes[node1];
    nodes[node1] = node0;
}

int main()
{
    FASTIO();

    int m, n, v;
    cin >> m >> n;

    while (m && n)
    {
        v = 0;
        table.clear();
        memset(nodes, -1, sizeof(nodes));
        for (int i = 0; i < n; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            table.push_back({ z, x, y });
        }
        sort(table.begin(), table.end());
        for (const auto& elem : table)
        {
            int lhsp = find_node(nodes, elem[1]);
            int rhsp = find_node(nodes, elem[2]);
            if (lhsp == rhsp)
                v += elem[0];
            else
                union_node(nodes, lhsp, rhsp);
        }
        cout << v << '\n';
        cin >> m >> n;
    }
}