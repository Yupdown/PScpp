#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SIZE_NODE = 202;

int capacity[SIZE_NODE][SIZE_NODE];
int cost[SIZE_NODE][SIZE_NODE];

int network_flow(int n, int src, int snk)
{
	static int flow[SIZE_NODE][SIZE_NODE];
	static int dist[SIZE_NODE];
	static int parent[SIZE_NODE];
	static int queued[SIZE_NODE];
	int sum = 0;

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

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		capacity[200][i] = v;
	}
	for (int i = 0; i < m; ++i)
	{
		int v;
		cin >> v;
		capacity[100 + i][201] = v;
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int v;
			cin >> v;
			capacity[j][100 + i] = INT_MAX;
			cost[100 + i][j] = -v;
			cost[j][100 + i] = v;
		}
	}

	cout << network_flow(SIZE_NODE, 200, 201);
}