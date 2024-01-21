#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<pair<int, int64_t>> edge[100000];
int parent[100000][17];
int depth[100000];
int64_t cost[100000];

inline int log2int(int x)
{
	int ret = 0;
	while (x >>= 1)
		++ret;
	return ret;
}

void initialize_tree(int curr, int last)
{
	depth[curr] = depth[last] + 1;

	parent[curr][0] = last;
	for (int i = 1; i < 17; ++i)
		parent[curr][i] = parent[parent[curr][i - 1]][i - 1];

	for (auto& next_node : edge[curr])
	{
		if (next_node.first != last)
		{
			cost[next_node.first] = cost[curr] + next_node.second;
			initialize_tree(next_node.first, curr);
		}
	}
}

int lca(int u, int v)
{
	if (depth[u] > depth[v])
		return lca(parent[u][log2int(depth[u] - depth[v])], v);
	if (depth[u] < depth[v])
		return lca(u, parent[v][log2int(depth[v] - depth[u])]);

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
		int u, v, w;
		cin >> u >> v >> w;
		edge[u - 1].push_back(make_pair(v - 1, w));
		edge[v - 1].push_back(make_pair(u - 1, w));
	}

	initialize_tree(0, 0);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int c, u, v, k;
		cin >> c >> u >> v;
		int ance = lca(u - 1, v - 1);

		switch (c)
		{
		case 1:
			cout << cost[u - 1] + cost[v - 1] - cost[ance] * 2 << '\n';
			break;
		case 2:
			cin >> k;
			{
				--k;
				int nk = u - 1;
				if (depth[u - 1] - depth[ance] < k)
				{
					k = depth[v - 1] + depth[u - 1] - depth[ance] * 2 - k;
					nk = v - 1;
				}
				int exp = 0;
				while (k > 0)
				{
					if (k & 1)
						nk = parent[nk][exp];
					k >>= 1;
					++exp;
				}
				cout << nk + 1 << '\n';
			}
			break;
		}
	}
}