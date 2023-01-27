#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int in[1000];
int dp[1000][2];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> in[i];

	for (int i = 0; i < n; ++i) {
		int j = n - i - 1;
		int v0max = 0;
		int v1max = 0;
		for (int k = 0; k < n; ++k) {
			if (k < i && in[i] > in[k])
				v0max = max(v0max, dp[k][0]);
			if (k > j && in[j] > in[k])
				v1max = max(v1max, dp[k][1]);
		}
		dp[i][0] = v0max + 1;
		dp[j][1] = v1max + 1;
	}

	int r = 0;
	for (int i = 0; i < n; ++i)
		r = max(r, dp[i][0] + dp[i][1] - 1);

	cout << r;
}