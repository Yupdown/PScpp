#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[15][1 << 14];

void calc(int m, int i, int j, int bitmask, int v)
{
	int inv = ~bitmask & (1 << m) - 1;
	(table[i + 1][inv] += v) %= 9901;

	while (j < m - 1)
	{
		if ((bitmask >> j & 3) == 0)
			calc(m, i, j + 2, bitmask | (3 << j), v);
		++j;
	}
}

int main()
{
	FASTIO();

	int n, m;
	cin >> m >> n;

	table[0][0] = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 1 << m; ++j)
		{
			if (table[i][j] == 0)
				continue;
			calc(m, i, 0, j, table[i][j]);
		}
	}

	cout << table[n][0];
}