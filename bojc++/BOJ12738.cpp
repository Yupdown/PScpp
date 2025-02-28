#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int dp[1000000];

int main()
{
	FASTIO();

	int n, l = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		int* pos = lower_bound(dp, dp + l, v);
		*pos = v;
		if (pos - dp >= l)
			++l;
	}

	cout << l;
}