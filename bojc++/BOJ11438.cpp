#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> edge[100001];
int parent[100001][18];
int depth[100001];

void initialize_tree(int p, int c, int d)
{
	parent[c][0] = p;
	depth[c] = d;

	for (int i = 1; i < 18; ++i)
	{
		parent[c][i] = parent[parent[c][i - 1]][i - 1];

		if (parent[c][i] == 0)
			break;
	}

	for (int i = 0; i < edge[c].size(); ++i)
	{
		if (edge[c][i] != p)
			initialize_tree(c, edge[c][i], d + 1);
	}
}

int lowest_common_ancestor(int u, int v)
{
	if (depth[v] > depth[u])
		swap(u, v);

	int d = depth[u] - depth[v];

	for (int i = 0; d >> i > 0; ++i)
	{
		if ((d >> i) & 1)
			u = parent[u][i];
	}

	while (u != v)
	{
		int i = 0;

		while (parent[u][i] != parent[v][i])
			++i;

		if (i > 0)
			--i;

		u = parent[u][i];
		v = parent[v][i];
	}

	return u;
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
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	initialize_tree(0, 1, 0);

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << lowest_common_ancestor(a, b) << '\n';
	}

	return 0;
}