#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[3000];
int memo[3000][3001][2];

int main()
{
	FASTIO();

	int n, b;
	cin >> n >> b;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	memo[1][2][1] = table[1];
	for (int i = 2; i < n; ++i)
	{
		for (int j = 0; j <= b; ++j)
		{
			memo[i][j][0] = max(memo[i - 1][j][0], memo[i - 1][j][1]);
			if (j > 1)
				memo[i][j][1] = max(memo[i - 1][j - 1][1], memo[i - 2][j - 2][0]) + table[i];
		}
	}
	int ret = 0;
	for (int i = 0; i <= b; ++i)
	{
		ret = max(ret, memo[n - 1][i][0]);
		ret = max(ret, memo[n - 1][i][1]);
	}
	cout << ret;
}