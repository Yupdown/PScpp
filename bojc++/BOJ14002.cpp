#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int in[1000];
int dp[1000];
int el[1000];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> in[n - i - 1];

	for (int i = 0; i < n; ++i) {
		int vmax[2] = { 0, -1 };
		for (int j = 0; j < i; ++j) {
			if (in[i] < in[j] && dp[j] >= vmax[0]) {
				vmax[0] = dp[j];
				vmax[1] = j;
			}
		}
		dp[i] = vmax[0] + 1;
		el[i] = vmax[1];
	}

	int r = max_element(dp, dp + n) - dp;
	cout << dp[r] << '\n';
	for (; r >= 0; r = el[r])
		cout << in[r] << ' ';
}