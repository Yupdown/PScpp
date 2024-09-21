#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<pair<int, long long>> edges[200000];
int horse[200000];
long long result1[200000][2];
long long result2[200000][2];
constexpr long long INF = LLONG_MAX >> 4;

void dijkstra(int n, int p, decltype(result1) result)
{
	for (int i = 0; i < n; ++i)
	{
		result[i][0] = INF;
		result[i][1] = INF;
	}
	priority_queue<pair<long long, int>> pq1;
	priority_queue<pair<long long, int>> pq2;
	if (horse[p])
	{
		pq2.emplace(0, p);
		result[p][1] = 0;
	}
	else
	{
		pq1.emplace(0, p);
		result[p][0] = 0;
	}
	while (!pq1.empty())
	{
		auto [w, n] = pq1.top();
		pq1.pop();
		if (result[n][0] < -w)
			continue;
		for (auto& [np, wp] : edges[n])
		{
			long long w = result[n][0] + wp;
			if (horse[np])
			{
				if (w < result[np][1])
				{
					pq2.emplace(-w, np);
					result[np][1] = w;
				}
			}
			else if (w < result[np][0])
			{
				pq1.emplace(-w, np);
				result[np][0] = w;
			}
		}
	}
	while (!pq2.empty())
	{
		auto [w, n] = pq2.top();
		pq2.pop();
		if (result[n][1] < -w)
			continue;
		for (auto& [np, wp] : edges[n])
		{
			long long w = result[n][1] + wp / 2;
			if (w < result[np][1])
			{
				pq2.emplace(-w, np);
				result[np][1] = w;
			}
		}
	}
}

int main()
{
	FASTIO();
	int t;
	cin >> t;

	while (t--)
	{
		int n, m, h;
		cin >> n >> m >> h;
		for (int i = 0; i < h; ++i)
		{
			int v;
			cin >> v;
			horse[v - 1] = 1;
		}
		for (int i = 0; i < m; ++i)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edges[u - 1].emplace_back(v - 1, w);
			edges[v - 1].emplace_back(u - 1, w);
		}
		dijkstra(n, 0, result1);
		dijkstra(n, n - 1, result2);
		long long ret = INF;
		for (int i = 0; i < n; ++i)
			ret = min(ret, max(min(result1[i][0], result1[i][1]), min(result2[i][0], result2[i][1])));
		cout << (ret < INF ? ret : -1) << '\n';
		for (int i = 0; i < n; ++i)
		{
			edges[i].clear();
			horse[i] = 0;
		}
	}
}