#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edge[50000];
int parent[50000][16];
int depth[50000];

void initialize_tree(int curr, int last)
{
	depth[curr] = depth[last] + 1;

	parent[curr][0] = last;
	for (int i = 1; i < 16; ++i)
		parent[curr][i] = parent[parent[curr][i - 1]][i - 1];

	for (int next_node : edge[curr])
	{
		if (next_node != last)
			initialize_tree(next_node, curr);
	}
}

int lca(int u, int v)
{
	if (depth[u] > depth[v])
		return lca(parent[u][(int)log2(depth[u] - depth[v])], v);
	if (depth[u] < depth[v])
		return lca(u, parent[v][(int)log2(depth[v] - depth[u])]);

	if (u == v)
		return u;

	int n = 1;
	while (parent[u][n] != parent[v][n])
		++n;
	return lca(parent[u][n - 1], parent[v][n - 1]);
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		edge[u - 1].push_back(v - 1);
		edge[v - 1].push_back(u - 1);
	}

	initialize_tree(0, -1);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		cout << lca(u - 1, v - 1) + 1 << '\n';
	}
}