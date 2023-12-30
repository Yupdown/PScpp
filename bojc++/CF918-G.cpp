#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

vector<pair<int, int64>> adj[1000];
int64 si[1000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i)
			adj[i].clear();

		for (int i = 0; i < m; ++i)
		{
			int a, b, w;
			cin >> a >> b >> w;

			adj[a - 1].push_back({ b - 1, w });
			adj[b - 1].push_back({ a - 1, w });
		}

		for (int i = 0; i < n; ++i)
			cin >> si[i];

		priority_queue<tuple<int64, int, int64>> pq;
		vector<vector<int64>> dist(n, vector<int64>(1024, LLONG_MAX));
		pq.push({ 0, 0, si[0] });
		dist[0][si[0]] = 0;

		while (!pq.empty())
		{
			auto [cur_dist, cur, s] = pq.top();
			pq.pop();

			if (dist[cur][s] < -cur_dist)
				continue;

			for (auto& p : adj[cur])
			{
				int64 next_dist = -cur_dist + p.second * s;
				int next = p.first;
				int64 next_s = min(s, si[next]);

				if (dist[next][next_s] > next_dist)
				{
					dist[next][next_s] = next_dist;
					pq.push({ -next_dist, next, next_s });
				}
			}
		}

		int64 min_dist = LLONG_MAX;
		for (int i = 0; i < 1024; ++i)
			min_dist = min(min_dist, dist[n - 1][i]);

		cout << min_dist << '\n';
	}
}