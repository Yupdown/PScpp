#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int in[1000];
int dp[1000];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> in[i];

	for (int i = 0; i < n; ++i) {
		int vmax = 0;
		for (int j = 0; j < i; ++j) {
			if (in[i] > in[j])
				vmax = max(vmax, dp[j]);
		}
		dp[i] = vmax + in[i];
	}

	cout << *max_element(dp, dp + n);
}