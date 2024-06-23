#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char s[32];
long long table[20];
long long dp[20][20];

// num of integers are n - 1
long long solution(int l, int r)
{
	if (l + 1 == r)
		return table[l];
	if (dp[l][r] >= 0)
		return dp[l][r];
	long long vmin = INT64_MAX;
	for (int i = l + 1; i < r; ++i)
	{
		auto lhs = solution(l, i);
		auto rhs = solution(i, r);
		auto v = min(lhs + rhs, lhs * rhs);
		vmin = min(vmin, v);
	}
	return dp[l][r] = vmin;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n >> s;

		long long v = INT64_MAX;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
			{
				if (j < i)
					table[j] = s[j] - '0';
				else if (j > i)
					table[j] = s[j + 1] - '0';
				else
					table[j] = (s[j] - '0') * 10 + s[j + 1] - '0';
			}
			memset(dp, -1, sizeof(dp));
			v = min(v, solution(0, n - 1));
		}
		cout << v << '\n';
	}
}