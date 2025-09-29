#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<int> edges[200000];
pair<int, int> memo[200000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].emplace_back(b - 1);
		edges[b - 1].emplace_back(a - 1);
	}
	memset(memo, -1, sizeof(memo));
	memo[0].first = 0;
	memo[n - 1].second = 0;
	queue<pair<int, bool>> bfs;
	bfs.emplace(0, false);
	bfs.emplace(n - 1, true);
	while (!bfs.empty())
	{
		const auto [node, mode] = bfs.front();
		bfs.pop();
		for (int node_next : edges[node])
		{
			auto& target = mode ? memo[node_next].second : memo[node_next].first;
			if (target >= 0)
				continue;
			target = (mode ? memo[node].second : memo[node].first) + 1;
			bfs.emplace(node_next, mode);
		}
	}
	map<pair<int, int>, pair<int, int>> count_table;
	for (int i = 1; i < n - 1; ++i)
	{
		if (memo[i].first + memo[i].second != memo[0].second)
			continue;
		auto& target = count_table[memo[i]];
		target.first = i;
		target.second++;
	}
	for (const auto& [k, v] : count_table)
	{
		if (v.second == 1)
		{
			cout << v.first + 1;
			return 0;
		}
	}
	cout << 1;
}