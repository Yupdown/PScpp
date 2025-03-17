#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1001][1001];

int main()
{
	FASTIO();
	memset(table, 0x10, sizeof(table));

	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < m; ++i)
	{
		int ai, bi, ti;
		cin >> ai >> bi >> ti;
		table[ai][bi] = min(table[ai][bi], ti);
		table[bi][ai] = min(table[bi][ai], ti);
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i)
		ret = max(ret, table[x][i]);
	cout << ret * 2;
}