#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SEGBASE = 1 << 11;
int seg[SEGBASE << 1][SEGBASE << 1];

int query_sub(int i, int k, int l)
{
	int ret = 0;
	int p = SEGBASE + k;
	int q = SEGBASE + l;
	while (p <= q)
	{
		if (p & 1)
			ret = max(ret, seg[i][p]);
		if (~q & 1)
			ret = max(ret, seg[i][q]);
		p = (p + 1) / 2;
		q = (q - 1) / 2;
	}
	return ret;
}

int query(int i, int j, int k, int l)
{
	int ret = 0;
	int p = SEGBASE + i;
	int q = SEGBASE + j;
	while (p <= q)
	{
		if (p & 1)
			ret = max(ret, query_sub(p, k, l));
		if (~q & 1)
			ret = max(ret, query_sub(q, k, l));
		p = (p + 1) / 2;
		q = (q - 1) / 2;
	}
	return ret;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		seg[SEGBASE + y1][SEGBASE + x1]++;
		seg[SEGBASE + y1][SEGBASE + x2]--;
		seg[SEGBASE + y2][SEGBASE + x1]--;
		seg[SEGBASE + y2][SEGBASE + x2]++;
	}
	for (int i = 1; i < SEGBASE; ++i)
	{
		for (int j = 0; j < SEGBASE; ++j)
			seg[SEGBASE + i][SEGBASE + j] += seg[SEGBASE + i - 1][SEGBASE + j];
	}
	for (int i = 0; i < SEGBASE; ++i)
	{
		for (int j = 1; j < SEGBASE; ++j)
			seg[SEGBASE + i][SEGBASE + j] += seg[SEGBASE + i][SEGBASE + j - 1];
	}
	for (int i = 0; i < SEGBASE; ++i)
	{
		for (int j = SEGBASE - 1; j > 0; --j)
			seg[SEGBASE + i][j] = max(seg[SEGBASE + i][j << 1], seg[SEGBASE + i][j << 1 | 1]);
	}
	for (int i = SEGBASE - 1; i > 0; --i)
	{
		for (int j = 0; j < SEGBASE << 1; ++j)
			seg[i][j] = max(seg[i << 1][j], seg[i << 1 | 1][j]);
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << query(a, c - 1, b, d - 1) << '\n';
	}
}