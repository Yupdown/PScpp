#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<pair<int, int>> table;
vector<pair<int, int>> query;
constexpr int SEGBASE = 1 << 18;
pair<int, int> seg[SEGBASE << 1];
map<int, int> conv;

int main()
{
	FASTIO();

	int n, m;
	cin >> n;
	table.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;
	cin >> m;
	query.resize(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> query[i].first >> query[i].second;
		table.emplace_back(query[i].first, 0);
		table.emplace_back(query[i].second, 0);
	}
	sort(table.begin(), table.end());

	seg[SEGBASE] = { table[0].second, table[0].second };
	conv[table[0].first] = 0;
	for (int i = 1, j = 0; i < table.size(); ++i)
	{
		if (table[i - 1].first + 1 < table[i].first)
			seg[SEGBASE + ++j] = { 0, 0 };
		if (table[i - 1].first < table[i].first)
			conv[table[i].first] = ++j;
		seg[SEGBASE + j] = { table[i].second, table[i].second };
	}

	for (int i = SEGBASE - 1; i > 0; --i)
	{
		int a = i * 2;
		int b = a + 1;
		seg[i] = { max(seg[a].first, seg[b].first), min(seg[a].second, seg[b].second) };
	}

	for (int i = 0; i < m; ++i)
	{
		bool c1 = true;
		bool c2 = true;
		bool c3 = true;

		int a = conv[query[i].first];
		int b = conv[query[i].second];
		int va = seg[SEGBASE + a].first;
		int vb = seg[SEGBASE + b].first;

		if (va == 0)
		{
			c1 = false;
			va = INT_MAX;
		}
		if (vb == 0)
		{
			c1 = false;
			vb = va == 0 ? INT_MAX : va;
		}
		c2 = va >= vb;
		int p = SEGBASE + a + 1;
		int q = SEGBASE + b - 1;
		while (p <= q)
		{
			if (min(seg[p].second, seg[q].second) == 0)
				c1 = false;
			if (seg[p].first >= vb || seg[q].first >= vb)
				c3 = false;
			p = (p + 1) / 2;
			q = (q - 1) / 2;
		}
		if (!c2 || !c3)
			cout << "false\n";
		else if (c1)
			cout << "true\n";
		else
			cout << "maybe\n";
	}
}