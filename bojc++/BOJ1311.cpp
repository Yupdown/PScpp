#include <iostream>
#include <cmath>

using namespace std;

int dp[1 << 20];

int function(int n, int d[20][20], int i, int mask)
{
	if (i >= n)
		return 0;

	if (!dp[mask])
	{
		dp[mask] = 1048576;

		for (int j = 0; j < n; ++j)
		{
			if (mask & (1 << j))
				continue;

			dp[mask] = min(dp[mask], function(n, d, i + 1, mask | (1 << j)) + d[i][j]);
		}
	}

	return dp[mask];
}

int main()
{
	int n, d[20][20];
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> d[i][j];
	}

	cout << function(n, d, 0, 0) << endl;
	return 0;
}