#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<pair<int, int>> edges[100];

int main()
{
	FASTIO();

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[a].emplace_back(b, w);
	}
	vector<pair<int, int>> memo(m, { -1, INT_MAX });
	queue<int> q;
	memo[0] = { 0, 0 };
	q.push(0);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (const auto& [v, w] : edges[u])
		{
			if (memo[v].first < 0 || memo[v].first > memo[u].first + 1)
			{
				memo[v].first = memo[u].first + 1;
				memo[v].second = memo[u].second + w;
				q.push(v);
			}
			else if (memo[v].first == memo[u].first + 1)
				memo[v].second = min(memo[v].second, memo[u].second + w);
		}
	}
	cout << memo[1].second;
}