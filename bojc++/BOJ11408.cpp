#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SIZE_NODE = 802;

int capacity[SIZE_NODE][SIZE_NODE];
int cost[SIZE_NODE][SIZE_NODE];

pair<int, int> network_flow(int n, int src, int snk)
{
	static int flow[SIZE_NODE][SIZE_NODE];
	static int dist[SIZE_NODE];
	static int parent[SIZE_NODE];
	static int queued[SIZE_NODE];
	int sum = 0;
	int csum = 0;

	memset(flow, 0, sizeof(flow));
	while (true)
	{
		fill(begin(dist), end(dist), INT_MAX);
		fill(begin(parent), end(parent), -1);
		fill(begin(queued), end(queued), 0);
		queue<int> q;

		dist[src] = 0;
		parent[src] = src;
		queued[src] = 1;
		q.push(src);

		while (!q.empty())
		{
			int cur = q.front();
			queued[cur] = 0;
			q.pop();
			for (int nxt = 0; nxt < n; ++nxt)
			{
				if (capacity[cur][nxt] - flow[cur][nxt] > 0 && dist[cur] + cost[cur][nxt] < dist[nxt])
				{
					dist[nxt] = dist[cur] + cost[cur][nxt];
					parent[nxt] = cur;

					if (!queued[nxt])
					{
						q.push(nxt);
						queued[nxt] = 1;
					}
				}
			}
		}
		if (parent[snk] < 0)
			break;
		int v = INT_MAX;
		for (int p = snk; p != src; p = parent[p])
			v = min(v, capacity[parent[p]][p] - flow[parent[p]][p]);
		sum += v;
		for (int p = snk; p != src; p = parent[p])
		{
			csum += v * cost[parent[p]][p];
			flow[parent[p]][p] += v;
			flow[p][parent[p]] -= v;
		}
	}
	return make_pair(sum, csum);
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		capacity[800][i] = 1;
	for (int i = 0; i < m; ++i)
		capacity[400 + i][801] = 1;
	for (int i = 0; i < n; ++i)
	{
		int j;
		cin >> j;

		while (j-- > 0)
		{
			int v, w;
			cin >> v >> w;
			capacity[i][v + 399] = 1;
			cost[i][v + 399] = w;
			cost[v + 399][i] = -w;
		}
	}

	pair<int, int> ret = network_flow(SIZE_NODE, 800, 801);
	cout << ret.first << '\n' << ret.second;
}