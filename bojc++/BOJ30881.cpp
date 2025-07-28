#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// 1e+18 �ʰ��� -1�� �����ؾ� �ϴµ�, long long �� ����Կ��� �����÷ο찡 �� �� ������ �����϶�.
constexpr __int128 INF = 1000000000000000001;

// ��� ���� �̸��� D[i][j][k] = str[a]?
__int128 dijkstra(const vector<vector<pair<int, long long>>>& edges, int start, int end)
{
	vector<__int128> dist(edges.size(), INF);
	priority_queue<pair<__int128, int>> pq;
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty())
	{
		auto [d, node_curr] = pq.top();
		pq.pop();
		d = -d;
		if (dist[node_curr] < d)
			continue;
		for (const auto& [node_next, w] : edges[node_curr])
		{
			__int128 dp = d + w;
			if (dp >= dist[node_next])
				continue;
			dist[node_next] = dp;
			pq.emplace(-dp, node_next);
		}
	}

	return dist[end] >= INF ? -1 : dist[end];
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	// t�� Ȱ�� �׷����� 1������ 2�������� �Ÿ�, 2������ 1�������� �Ÿ��� ���� ���� ���̺�
	// �׷��� Ȱ�ڸ� ����� �� 2������ 1�������� ���� �Ÿ��� �̿��ؼ� �����ذ� ������ ��쵵 �־� �����ؾ� �Ѵ�.
	vector<pair<long long, long long>> memo;
	for (int i = 0; i < t; ++i)
	{
		int n, q;
		cin >> n >> q;
		vector<vector<pair<int, long long>>> edges(n);
		for (int i = 0; i < q; ++i)
		{
			long long v, w, x;
			cin >> v >> w >> x;
			if (x < 0)
			{
				auto [xl, xr] = memo[-1 - x];
				if (xl >= 0)
					edges[v - 1].emplace_back(w - 1, xl);
				if (xr >= 0)
					edges[w - 1].emplace_back(v - 1, xr);
			}
			else
				edges[v - 1].emplace_back(w - 1, x);
		}
		memo.emplace_back(dijkstra(edges, 0, 1), dijkstra(edges, 1, 0));
	}
	cout << memo[t - 1].first;
}