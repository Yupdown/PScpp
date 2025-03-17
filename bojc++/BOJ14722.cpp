#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1000][1000];
int memo[1000][1000][3];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n * n; ++i)
		cin >> table[i / n][i % n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (table[i][j] == 0)
				memo[i][j][0] = max(memo[i][j][0], 1);
			int c = table[i][j];
			int l = (c + 2) % 3;
			if (i > 0 && memo[i - 1][j][l] > 0)
				memo[i][j][c] = max(memo[i][j][c], memo[i - 1][j][l] + 1);
			if (j > 0 && memo[i][j - 1][l] > 0)
				memo[i][j][c] = max(memo[i][j][c], memo[i][j - 1][l] + 1);
			for (int k = 0; k < 3; ++k)
			{
				if (i > 0)
					memo[i][j][k] = max(memo[i][j][k], memo[i - 1][j][k]);
				if (j > 0)
					memo[i][j][k] = max(memo[i][j][k], memo[i][j - 1][k]);
			}
		}
	}
	cout << *max_element(memo[n - 1][n - 1], memo[n - 1][n - 1] + 3);
}