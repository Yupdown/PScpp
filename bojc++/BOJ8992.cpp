#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SIZE_NODE = 402;

int capacity[SIZE_NODE][SIZE_NODE];
int cost[SIZE_NODE][SIZE_NODE];

using int64 = long long;

struct vector2d
{
	int64 x;
	int64 y;
};

inline int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
	int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	return result > 0 ? 1 : result < 0 ? -1 : 0;
}

bool line_intersection(const vector2d& p1, const vector2d& p2, const vector2d& p3, const vector2d& p4)
{
	int o1 = orientation(p1, p2, p3);
	int o2 = orientation(p1, p2, p4);
	int o3 = orientation(p3, p4, p1);
	int o4 = orientation(p3, p4, p2);

	return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

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

pair<vector2d, vector2d> table[2][200];
int weight[2][200];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, m;
		cin >> n >> m;

		memset(capacity, 0, sizeof(capacity));
		memset(cost, 0, sizeof(cost));

		for (int i = 0; i < n; ++i)
			cin >> table[0][i].first.x >> table[0][i].first.y >> table[0][i].second.x >> table[0][i].second.y >> weight[0][i];
		for (int i = 0; i < m; ++i)
			cin >> table[1][i].first.x >> table[1][i].first.y >> table[1][i].second.x >> table[1][i].second.y >> weight[1][i];
		for (int i = 0; i < n; ++i)
			capacity[0][i + 2] = 1;
		for (int i = 0; i < m; ++i)
			capacity[i + n + 2][1] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (line_intersection(table[0][i].first, table[0][i].second, table[1][j].first, table[1][j].second))
				{
					int w = weight[0][i] * weight[1][j];
					capacity[i + 2][j + n + 2] = 1;
					cost[i + 2][j + n + 2] = -w;
					cost[j + n + 2][i + 2] = w;
				}
			}
		}

		auto p = network_flow(n + m + 2, 0, 1);
		cout << p.first << ' ' << -p.second << '\n';
	}
}