#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edge[100000];
int parent[100001][18];
int depth[100001];

void initialize_tree(int p, int c, int d)
{
	parent[c][0] = p;
	depth[c] = d;
	for (int i = 1; i < 18; ++i)
	{
		if ((parent[c][i] = parent[parent[c][i - 1]][i - 1]) == 0)
			break;
	}
	for (auto e : edge[c])
	{
		if (e != p)
			initialize_tree(c, e, d + 1);
	}
}

int lca(int u, int v)
{
	if (depth[v] > depth[u])
		swap(u, v);
	int d = depth[u] - depth[v];
	for (int i = 0; d >> i > 0; ++i)
	{
		if (d >> i & 1)
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

int mid(int u, int v)
{
	int p = lca(u, v);
	int lu = depth[u] - depth[p];
	int lv = depth[v] - depth[p];
	if ((lu + lv) & 1)
		return -1;
	int hl = (lu + lv) / 2;
	int m = lu > lv ? u : v;
	for (int i = 0; hl >> i > 0; ++i)
	{
		if (hl >> i & 1)
			m = parent[m][i];
	}
	return m;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	initialize_tree(0, 1, 0);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int m[] = { mid(a, b), mid(b, c), mid(a, c) };
		sort(m, m + 3);
		if (m[0] < 0)
			cout << "-1\n";
		else if (m[0] == m[1])
			cout << m[0] << '\n';
		else if (m[1] == m[2])
			cout << m[1] << '\n';
		else
			cout << "-1\n";
	}
}