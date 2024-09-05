#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[32][32];
int memo[900][900];

int main()
{
	FASTIO();

	int n, a, b;
	cin >> n >> a >> b;
	int n2 = n * n;
	int n4 = n2 * n2;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	memset(memo, 0x10, sizeof(memo));
	for (int i = 0; i < n2; ++i)
	{
		int r = i / n;
		int c = i % n;
		if (r > 0)
		{
			int v = table[r][c] == table[r - 1][c] ? a : b;
			memo[i][i - n] = v;
			memo[i - n][i] = v;
		}
		if (c > 0)
		{
			int v = table[r][c] == table[r][c - 1] ? a : b;
			memo[i][i - 1] = v;
			memo[i - 1][i] = v;
		}
		memo[i][i] = 0;
	}
	for (int m = 0; m < n2; ++m)
	{
		for (int s = 0; s < n2; ++s)
		{
			for (int e = 0; e < n2; ++e)
				memo[s][e] = min(memo[s][e], memo[s][m] + memo[m][e]);
		}
	}
	int ret = 0;
	for (int i = 0; i < n4; ++i)
		ret = max(ret, memo[i / n2][i % n2]);
	cout << ret;
}