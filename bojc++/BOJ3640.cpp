#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SIZE_NODE = 2000;

int capacity[SIZE_NODE][SIZE_NODE];
int cost[SIZE_NODE][SIZE_NODE];

int network_flow(int n, int src, int snk)
{
	static int flow[SIZE_NODE][SIZE_NODE];
	static int dist[SIZE_NODE];
	static int parent[SIZE_NODE];
	static int queued[SIZE_NODE];
	int sum = 0, cnt = 2;

	memset(flow, 0, sizeof(flow));
	while (cnt-- > 0)
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
		int v = INT_MAX;
		for (int p = snk; p != src; p = parent[p])
			v = min(v, capacity[parent[p]][p] - flow[parent[p]][p]);
		for (int p = snk; p != src; p = parent[p])
		{
			sum += v * cost[parent[p]][p];
			flow[parent[p]][p] += v;
			flow[p][parent[p]] -= v;
		}
	}
	return sum;
}

int main()
{
	FASTIO();

	int v, e;
	while (cin >> v >> e)
	{
		memset(capacity, 0, sizeof(capacity));
		memset(cost, 0, sizeof(cost));

		for (int i = 1; i < v - 1; ++i)
			capacity[i * 2][i * 2 + 1] = 1;

		for (int i = 0; i < e; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;

			capacity[a * 2 - 1][b * 2 - 2] = 1;
			cost[a * 2 - 1][b * 2 - 2] = c;
			cost[b * 2 - 2][a * 2 - 1] = -c;
		}

		cout << network_flow(v * 2, 1, v * 2 - 2) << '\n';
	}
}