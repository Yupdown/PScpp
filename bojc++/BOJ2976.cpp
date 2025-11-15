#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1000];
int memo[1000][1000];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	memset(memo, 0x10, sizeof(memo));
	memo[0][0] = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j - i >= 0)
				memo[i][j] = min(memo[i][j], memo[i - 1][j - i] + table[j]);
		}
		for (int j = n - 1; j >= 0; --j)
		{
			if (i + j < n)
				memo[i][j] = min(memo[i][j], memo[i][i + j] + table[j]);
		}
	}
	int ret = 0x10101010;
	for (int i = 0; i < n; ++i)
		ret = min(ret, memo[i][n - 1]);
	cout << ret;
}