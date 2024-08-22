#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[2000];
int memo[2001][21];

int main()
{
	FASTIO();

	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	memset(memo, 0x7F, sizeof(memo));
	memo[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= d; ++j)
		{
			memo[i + 1][j] = min(memo[i + 1][j], memo[i][j] + table[i]);
			if (j > 0)
				memo[i + 1][j] = min(memo[i + 1][j], (memo[i][j - 1] + 5) / 10 * 10 + table[i]);
		}
	}

	int ret = INT_MAX;
	for (int i = 0; i <= d; ++i)
		ret = min(ret, (memo[n][i] + 5) / 10 * 10);
	cout << ret;
}