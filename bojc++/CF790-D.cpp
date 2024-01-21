#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[200][200];
int memo[200][200][4];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, m;
		cin >> n >> m;

		memset(memo, 0, sizeof(memo));

		for (int i = 0; i < n * m; ++i)
			cin >> table[i / m][i % m];

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				memo[i][j][0] += table[i][j];
				memo[i][j][1] += table[i][j];

				if (i > 0)
				{
					if (j > 0)
						memo[i][j][0] += memo[i - 1][j - 1][0];
					if (j < m - 1)
						memo[i][j][1] += memo[i - 1][j + 1][1];
				}
			}
		}

		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = 0; j < m; ++j)
			{
				memo[i][j][2] += table[i][j];
				memo[i][j][3] += table[i][j];

				if (i < n - 1)
				{
					if (j > 0)
						memo[i][j][2] += memo[i + 1][j - 1][2];
					if (j < m - 1)
						memo[i][j][3] += memo[i + 1][j + 1][3];
				}
			}
		}

		int vmax = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				vmax = max(vmax, accumulate(memo[i][j], memo[i][j] + 4, table[i][j] * -3));
		}
		cout << vmax << '\n';
	}
}