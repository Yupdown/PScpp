#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<pair<int, int>> edges[1000];
int result[1000];
int path[1000];

void dijkstra(int p)
{
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, p);
	result[p] = 0;
	while (!pq.empty())
	{
		auto [w, n] = pq.top();
		pq.pop();
		if (-w > result[n])
			continue;
		for (auto& [np, wp] : edges[n])
		{
			int w = result[n] + wp;
			if (w < result[np])
			{
				pq.emplace(-w, np);
				result[np] = w;
				path[np] = n;
			}
		}
	}
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[a - 1].emplace_back(b - 1, w);
		edges[b - 1].emplace_back(a - 1, w);
	}
	int a, b, c;
	cin >> a >> b >> c;
	a--, b--, c--;
	int vmin = INT_MAX, imin = 0;
	for (int i = 0; i < n; ++i)
	{
		memset(result, 1, sizeof(result));
		memset(path, -1, sizeof(path));
		dijkstra(i);
		int v = result[a] + result[b] + result[c];
		if (v < vmin)
			vmin = v, imin = i;
	}

	memset(result, 1, sizeof(result));
	memset(path, -1, sizeof(path));
	dijkstra(imin);

	vector<pair<int, int>> ret;
	while (path[a] >= 0)
	{
		ret.emplace_back(a, path[a]);
		a = path[a];
	}
	while (path[b] >= 0)
	{
		ret.emplace_back(b, path[b]);
		b = path[b];
	}
	while (path[c] >= 0)
	{
		ret.emplace_back(c, path[c]);
		c = path[c];
	}
	for (auto& p : ret)
	{
		if (p.first < p.second)
			swap(p.first, p.second);
	}
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	cout << vmin << ' ' << ret.size() << '\n';
	for (auto& p : ret)
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}