#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[100001], cnt;
vector<int> edges[100001];
vector<pair<int, int>> articulation;

int dfs(int node, int last_node)
{
	memo[node] = ++cnt;
	int ret = memo[node];

	for (int edge : edges[node])
	{
		if (edge == last_node)
			continue;
		else if (memo[edge] > 0)
			ret = min(ret, memo[edge]);
		else
		{
			int v = dfs(edge, node);
			if (v > memo[node])
				articulation.push_back(make_pair(min(node, edge), max(node, edge)));
			ret = min(ret, v);
		}
	}

	return ret;
}

int main()
{
	FASTIO();

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1, 0);
	sort(articulation.begin(), articulation.end());

	cout << articulation.size() << "\n";
	for (auto& edge : articulation)
		cout << edge.first << " " << edge.second << "\n";
}