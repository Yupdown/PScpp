#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<int> edges[3000];
int nodes[3000];

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

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		edges[u - 1].push_back(v - 1);
		edges[v - 1].push_back(u - 1);
	}

	vector<int> table(n);
	vector<bool> flag(n);
	vector<bool> ret;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	ret.push_back(true);
	flag[table.back() - 1] = true;
	memset(nodes, -1, sizeof(nodes));
	for (auto iter = table.crbegin() + 1; iter != table.crend(); ++iter)
	{
		int node = *iter - 1;
		flag[node] = true;
		for (int e : edges[node])
		{
			if (!flag[e])
				continue;
			int up = find_node(nodes, node);
			int vp = find_node(nodes, e);
			if (up != vp)
				union_node(nodes, up, vp);
		}
		ret.push_back(-nodes[find_node(nodes, node)] == distance(table.crbegin(), iter) + 1);
	}

	for (auto iter = ret.crbegin(); iter != ret.crend(); ++iter)
		cout << (*iter ? "YES\n" : "NO\n");
}