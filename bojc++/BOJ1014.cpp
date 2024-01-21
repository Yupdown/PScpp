#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[10][11];
int memo[10][1 << 10];

int calc1(int n, int m, int i, int b);
int calc2(int n, int m, int i, int j, int b, int bp);

int calc1(int n, int m, int i, int b)
{
	if (i >= n)
		return 0;
	if (memo[i][b] >= 0)
		return memo[i][b];
	return memo[i][b] = calc2(n, m, i, 0, b >> 1 | b << 1 & 1023, 0);
}

int calc2(int n, int m, int i, int j, int b, int bp)
{
	int vmax = calc1(n, m, i + 1, bp);
	for (int k = j; k < m; ++k)
	{
		if (table[i][k] == 'x')
			continue;
		if (b >> k & 1)
			continue;
		vmax = max(vmax, calc2(n, m, i, k + 2, b, bp | 1 << k) + 1);
	}
	return vmax;
}

int main()
{
	FASTIO();

	int c;
	cin >> c;

	while (c-- > 0)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> table[i];

		memset(memo, -1, sizeof(memo));
		cout << calc1(n, m, 0, 0) << '\n';
	}
}