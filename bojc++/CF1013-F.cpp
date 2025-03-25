#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char table[2000][2000];
long long memo[2][2000][2001];
constexpr long long MOD = 998244353;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, d;
		cin >> n >> m >> d;
		for (int i = 0; i < n; ++i)
		{
			cin >> table[i];
			memset(memo[0][i], 0, 8 * (m + 1));
			memset(memo[1][i], 0, 8 * (m + 1));
		}
		int dp = sqrt(d * d - 1);
		for (int i = 0; i < m; ++i)
		{
			if (table[n - 1][i] == 'X')
				memo[0][n - 1][i + 1] = 1;
		}
		for (int i = n - 1; i >= 0; --i)
		{
			// gather from different level
			if (i < n - 1)
			{
				for (int j = 0; j < m; ++j)
				{
					int b = max(j - dp, 0);
					int e = min(j + 1 + dp, m);
					if (table[i][j] == 'X')
					{
						memo[0][i][j + 1] += memo[0][i + 1][e] - memo[0][i + 1][b];
						memo[0][i][j + 1] += memo[1][i + 1][e] - memo[1][i + 1][b];
						memo[0][i][j + 1] %= MOD;
					}
				}
			}

			for (int j = 0; j < m; ++j)
				memo[0][i][j + 1] += memo[0][i][j];

			// gather from same level
			for (int j = 0; j < m; ++j)
			{
				int b = max(j - d, 0);
				int e = min(j + 1 + d, m);
				if (table[i][j] == 'X')
				{
					memo[1][i][j + 1] += (memo[0][i][e] - memo[0][i][b]) - (memo[0][i][j + 1] - memo[0][i][j]);
					memo[1][i][j + 1] %= MOD;
				}
			}

			for (int j = 0; j < m; ++j)
				memo[1][i][j + 1] += memo[1][i][j];
		}
		cout << (memo[0][0][m] + memo[1][0][m]) % MOD << "\n";
	}
}