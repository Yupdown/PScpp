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

constexpr long long MOD = 1'000'000'007;
pair<int, int> edges[2000];
long long v[2000];
int nodes[2000];

int main()
{
    FASTIO();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
        v[i] = i > 0 ? v[i - 1] * 3 % MOD : 1;
    }
    memset(nodes, -1, sizeof(nodes));
    long long ret = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        int fp = find_node(nodes, 0);
        int tp = find_node(nodes, n - 1);
        int ap = find_node(nodes, edges[i].first);
        int bp = find_node(nodes, edges[i].second);
        if ((fp == ap && tp == bp) || (fp == bp && tp == ap))
            ret = (ret + v[i]) % MOD;
        else if (ap != bp)
            union_node(nodes, ap, bp);
    }

    cout << ret;
}