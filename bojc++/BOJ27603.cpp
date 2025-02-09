#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<vector<pair<int, int>>> edges;
vector<int> result;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		edges.clear();
		edges.resize(n);
		result.clear();
		result.resize(m, 1);
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;
			edges[u - 1].emplace_back(v - 1, i);
			edges[v - 1].emplace_back(u - 1, i);
		}
		if (m == n * (n - 1) / 2)
		{
			for (auto [e, i] : edges[0])
				result[i] = 2;
			result[edges[0][0].second] = 3;
		}
		else
		{
			int p = 0;
			while (edges[p].size() == n - 1)
				++p;
			for (auto [e, i] : edges[p])
				result[i] = 2;
		}
		cout << *max_element(result.begin(), result.end()) << '\n';
		for (int r : result)
			cout << r << ' ';
		cout << '\n';
	}
}