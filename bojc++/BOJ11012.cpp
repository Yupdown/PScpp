#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SEGBASE = 1 << 17;
vector<pair<int, int>> seg[SEGBASE << 1];

void update_sub(int i, int y, int v)
{
	if (seg[i].back().second == v)
		return;
	if (y > seg[i].back().first)
		seg[i].emplace_back(y, v);
	else
		seg[i].back().second = v;
}

void update(int x, int y)
{
	int i = SEGBASE + x;
	update_sub(i, y, seg[i].back().second + 1);
	for (i >>= 1; i > 0; i >>= 1)
		update_sub(i, y, seg[i << 1].back().second + seg[i << 1 | 1].back().second);
}

int query(int x0, int x1, int y)
{
	int ret = 0;
	int p = SEGBASE + x0;
	int q = SEGBASE + x1;
	while (p <= q)
	{
		if (p & 1)
			ret += prev(lower_bound(seg[p].begin(), seg[p].end(), make_pair(y + 1, 0)))->second;
		if (~q & 1)
			ret += prev(lower_bound(seg[q].begin(), seg[q].end(), make_pair(y + 1, 0)))->second;
		p = (p + 1) / 2;
		q = (q - 1) / 2;
	}
	return ret;
}

pair<int, int> table[10000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		// first element is y, otherwise x
		for (int i = 0; i < n; ++i)
			cin >> table[i].second >> table[i].first;
		sort(table, table + n);
		for (int i = 0; i < SEGBASE << 1; ++i)
		{
			seg[i].clear();
			seg[i].emplace_back(-1, 0);
		}
		for (int i = 0; i < n; ++i)
			update(table[i].second, table[i].first);

		int ret = 0;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			ret += query(a, b, d) - query(a, b, c - 1);
		}

		cout << ret << '\n';
	}
}