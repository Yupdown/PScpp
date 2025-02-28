#include <iostream>
#include <cmath>

using namespace std;

int dp[101][100001];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	pair<int, int> wv[100];

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> wv[i].first >> wv[i].second;

	for (int i = 1; i < n + 1; ++i)
	{
		for (int w = 0; w <= k; ++w)
			dp[i][w] = w < wv[i - 1].first ? dp[i - 1][w] : max(dp[i - 1][w], dp[i - 1][w - wv[i - 1].first] + wv[i - 1].second);
	}

	cout << dp[n][k] << endl;
	return 0;
}