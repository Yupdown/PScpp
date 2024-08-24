#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using seginfo = tuple<int, int, int>;

constexpr int SEGBASE = 1 << 10;
int table[SEGBASE][SEGBASE];
int memo[SEGBASE][SEGBASE];
seginfo seg[SEGBASE << 1][SEGBASE << 1];

seginfo query_sub(int i, int k, int l)
{
	seginfo ret{ INT_MIN, 0, 0 };
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

seginfo query(int i, int j, int k, int l)
{
	seginfo ret{ INT_MIN, 0, 0 };
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

	int m, n, a, b, c, d;
	cin >> m >> n >> b >> a >> d >> c;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> table[i][j];
			seg[SEGBASE + i][SEGBASE + j] = make_tuple(0, i, j);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			memo[i + 1][j + 1] = memo[i + 1][j] + table[i][j];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			memo[i + 1][j + 1] += memo[i][j + 1];
	}
	for (int i = 0; i + c < n + 1; ++i)
	{
		for (int j = 0; j + d < m + 1; ++j)
			get<0>(seg[SEGBASE + i][SEGBASE + j]) = -(memo[i][j] - memo[i][j + d] - memo[i + c][j] + memo[i + c][j + d]);
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

	int vmax = INT_MIN;
	auto ret = make_tuple(0, 0, 0, 0);
	for (int i = 0; i + a < n + 1; ++i)
	{
		for (int j = 0; j + b < m + 1; ++j)
		{
			int v = memo[i][j] - memo[i][j + b] - memo[i + a][j] + memo[i + a][j + b];
			auto [vp, ip, jp] = query(i + 1, i + a - c - 1, j + 1, j + b - d - 1);
			if (v + vp > vmax)
			{
				vmax = v + vp;
				ret = make_tuple(j + 1, i + 1, jp + 1, ip + 1);
			}
		}
	}
	auto [j, i, jp, ip] = ret;
	cout << j << ' ' << i << '\n' << jp << ' ' << ip;
}