#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> edge[100001];
pair<int, pair<int, int>> parent[100001][18];
int depth[100001];

inline pair<int, int> process(pair<int, int> p, pair<int, int> v)
{
	p.first = min(p.first, v.first);
	p.second = max(p.second, v.second);
	return p;
}

void initialize_tree(int p, int c, int d, int w)
{
	parent[c][0] = { p, { w, w } };
	depth[c] = d;

	for (int i = 1; i < 18; ++i)
	{
		pair<int, pair<int, int>> half = parent[c][i - 1];
		pair<int, pair<int, int>> full = parent[half.first][i - 1];

		if (full.first == 0)
			break;

		parent[c][i].first = full.first;
		parent[c][i].second = process(half.second, full.second);
	}

	for (int i = 0; i < edge[c].size(); ++i)
	{
		if (edge[c][i].first != p)
			initialize_tree(c, edge[c][i].first, d + 1, edge[c][i].second);
	}
}

pair<int, int> get_result(int u, int v)
{
	pair<int, int> r = { 1000000, 0 };

	if (depth[v] > depth[u])
		swap(u, v);

	int d = depth[u] - depth[v];

	for (int i = 0; d >> i > 0; ++i)
	{
		if ((d >> i) & 1)
		{
			pair<int, pair<int, int>> node = parent[u][i];

			u = node.first;
			r = process(r, node.second);
		}
	}

	while (u != v)
	{
		int i = 0;

		while (parent[u][i].first != parent[v][i].first)
			++i;

		if (i > 0)
			--i;

		r = process(r, parent[u][i].second);
		r = process(r, parent[v][i].second);

		u = parent[u][i].first;
		v = parent[v][i].first;
	}

	return r;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;

		edge[a].push_back({ b, w });
		edge[b].push_back({ a, w });
	}

	initialize_tree(0, 1, 0, 0);

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		pair<int, int> result = get_result(a, b);
		cout << result.first << ' ' << result.second << '\n';
	}

	return 0;
}