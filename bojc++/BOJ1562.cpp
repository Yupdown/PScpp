#include <stdio.h>

int function(int dp[100][10][1024], int n, int i, int j, int bitmask)
{
	if (dp[i][j][bitmask])
		return dp[i][j][bitmask];

	if (i >= n)
		return dp[i][j][bitmask] = (bitmask == 1023);

	if (j > 0)
		dp[i][j][bitmask] += function(dp, n, i + 1, j - 1, bitmask | (1 << (j - 1)));

	if (j < 9)
		dp[i][j][bitmask] += function(dp, n, i + 1, j + 1, bitmask | (1 << (j + 1)));

	return dp[i][j][bitmask] %= 1000000000;
}

int main()
{
	int n, r, i, dp[100][10][1024] = { 0 };
	scanf("%d", &n);

	for (i = 1, r = 0; i < 10; i++)
		r = (r + function(dp, n - 1, 0, i, 1 << i)) % 1000000000;
	printf("%d\n", r);

	return 0;
}