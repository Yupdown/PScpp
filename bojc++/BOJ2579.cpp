#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int t[300];
int dp[300][2];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> t[i];

	dp[0][0] = t[0];
	dp[0][1] = t[0];

	for (int i = 1; i < n; ++i) {
		if (i > 1)
			dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + t[i];
		else
			dp[i][0] = t[i];
		dp[i][1] = dp[i - 1][0] + t[i];
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);
}