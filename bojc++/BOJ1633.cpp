#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> table[1000];
int memo[1001][16][16];

int main()
{
	FASTIO();

	int n = 0;
	while (cin >> table[n].first >> table[n].second)
		++n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 15; j >= 0; --j)
		{
			for (int k = 15; k >= 0; --k)
			{
				memo[i + 1][j][k] = max(memo[i + 1][j][k], memo[i][j][k]);
				if (j < 15)
					memo[i + 1][j + 1][k] = max(memo[i + 1][j + 1][k], memo[i][j][k] + table[i].first);
				if (k < 15)
					memo[i + 1][j][k + 1] = max(memo[i + 1][j][k + 1], memo[i][j][k] + table[i].second);
			}
		}
	}
	cout << memo[n][15][15];
}