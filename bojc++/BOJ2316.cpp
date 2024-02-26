#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int capacity[800][800];
int flow[800][800];

int network_flow(int n, int src, int snk)
{
	static int parent[800];
	memset(flow, 0, sizeof(flow));
	int sum = 0;
	while (true)
	{
		memset(parent, -1, sizeof(parent));
		queue<int> q;
		parent[src] = src;
		q.push(src);
		while (!q.empty() && parent[snk] < 0)
		{
			int cur = q.front();
			q.pop();
			for (int nxt = 0; nxt < n; ++nxt)
			{
				if (capacity[cur][nxt] - flow[cur][nxt] > 0 && parent[nxt] < 0)
				{
					q.push(nxt);
					parent[nxt] = cur;
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
			flow[parent[p]][p] += v;
			flow[p][parent[p]] -= v;
		}
		sum += v;
	}
	return sum;
}

int main()
{
	FASTIO();
	
	int n, p;
	cin >> n >> p;

	for (int i = 2; i < n; ++i)
		capacity[i * 2][i * 2 + 1] = 1;
	for (int i = 0; i < p; ++i)
	{
		int a, b;
		cin >> a >> b;
		capacity[a * 2 - 1][b * 2 - 2] += 1;
		capacity[b * 2 - 1][a * 2 - 2] += 1;
	}

	cout << network_flow(n * 2, 1, 2);
}