#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> edge[65536];
pair<int, int> parent[65536][16];
int depth[65536];

void initialize_tree(int p, int c, int d, int w)
{
	parent[c][0] = { p, w };
	depth[c] = d;

	for (int i = 1; i < 16; ++i)
	{
		pair<int, int> half = parent[c][i - 1];
		pair<int, int> full = parent[half.first][i - 1];

		if (full.first == 0)
			break;

		parent[c][i] = full;
		parent[c][i].second += half.second;
	}

	for (int i = 0; i < edge[c].size(); ++i)
	{
		if (edge[c][i].first != p)
			initialize_tree(c, edge[c][i].first, d + 1, edge[c][i].second);
	}
}

int distance(int u, int v)
{
	int r = 0;

	if (depth[v] > depth[u])
		swap(u, v);

	int d = depth[u] - depth[v];

	for (int i = 0; d >> i > 0; ++i)
	{
		if ((d >> i) & 1)
		{
			pair<int, int> node = parent[u][i];

			u = node.first;
			r += node.second;
		}
	}

	while (u != v)
	{
		int i = 0;

		while (parent[u][i].first != parent[v][i].first)
			++i;

		if (i > 0)
			--i;

		r += parent[u][i].second;
		r += parent[v][i].second;

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

		cout << distance(a, b) << endl;
	}

	return 0;
}