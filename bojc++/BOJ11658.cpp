#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SEGBASE = 1 << 10;
int seg[SEGBASE << 1][SEGBASE << 1];

void update(int i, int j)
{
	if (j == 0)
		return;
	if (j < SEGBASE)
		seg[i][j] = seg[i][j << 1] + seg[i][j << 1 | 1];
	update(i, j >> 1);
	for (i >>= 1; i > 0; i >>= 1)
		seg[i][j] = seg[i << 1][j] + seg[i << 1 | 1][j];
}

int query_sub(int i, int k, int l)
{
	int ret = 0;
	int p = SEGBASE + k;
	int q = SEGBASE + l;
	while (p <= q)
	{
		if (p & 1)
			ret += seg[i][p];
		if (~q & 1)
			ret += seg[i][q];
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
			ret += query_sub(p, k, l);
		if (~q & 1)
			ret += query_sub(q, k, l);
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
	for (int i = 0; i < n * n; ++i)
		cin >> seg[SEGBASE + i / n][SEGBASE + i % n];

	for (int i = 0; i < SEGBASE; ++i)
	{
		for (int j = SEGBASE - 1; j > 0; --j)
			seg[SEGBASE + i][j] = seg[SEGBASE + i][j << 1] + seg[SEGBASE + i][j << 1 | 1];
	}
	for (int i = SEGBASE - 1; i > 0; --i)
	{
		for (int j = 0; j < SEGBASE << 1; ++j)
			seg[i][j] = seg[i << 1][j] + seg[i << 1 | 1][j];
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d;
		switch (a)
		{
		case 0:
			b = SEGBASE + b - 1;
			c = SEGBASE + c - 1;
			seg[b][c] = d;
			update(b, c);
			break;
		case 1:
			cin >> e;
			cout << query(b - 1, d - 1, c - 1, e - 1) << '\n';
			break;
		}
	}
}