#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[16][16];
char dp[15][10][32768];

int solution(int n, int m, int c, int p, int mask)
{
	int ret = m;

	if (dp[c][p][mask] > 0)
		return dp[c][p][mask];

	for (int i = 0; i < n; ++i)
	{
		int v = table[c][i] - '0';
		if (v < p)
			continue;
		if (mask & (1 << i))
			continue;

		ret = max(ret, solution(n, m + 1, i, v, mask | (1 << i)));
	}

	return dp[c][p][mask] = ret;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	cout << solution(n, 1, 0, 0, 1) << '\n';
	return 0;
}