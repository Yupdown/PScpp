#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int flags[1000];
int nodes[1000];
vector<tuple<int, int, int>> edges;

inline int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
	if (flags[node0] > 0)
		nodes[node1] = node0;
	else if (flags[node1] > 0)
		nodes[node0] = node1;
	else
		nodes[node1] = node0;
}

int main()
{
	FASTIO();

	int n, m, k;
	cin >> n >> m >> k;

	memset(nodes, -1, sizeof(nodes));
	edges.reserve(m);

	for (int i = 0; i < k; ++i)
	{
		int v;
		cin >> v;
		flags[v - 1] = i + 1;
	}

	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(w, u - 1, v - 1);
	}

	int ret = 0;
	sort(edges.begin(), edges.end());
	for (const auto& [w, u, v] : edges)
	{
		int up = find_node(nodes, u);
		int vp = find_node(nodes, v);

		if (up == vp)
			continue;
		if (flags[up] && flags[vp])
			continue;

		union_node(nodes, up, vp);
		ret += w;
	}

	cout << ret;
}