#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char input[16];
int64_t dp[16][128][3];

const int segments[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };

int main()
{
	FASTIO();

	cin >> input;
	int n = strlen(input);

	int64_t num = 0, mod = 1;
	for (int i = 0; i < n; ++i, mod *= 10)
		num = num * 10 + input[i] - '0';

	for (int i = 0; i < n + 1; ++i)
		for (int j = 0; j < 128; ++j)
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = INT64_MAX;
	dp[0][0][1] = 0;

	for (int i = 0; i < n; ++i)
	{
		int64_t base = 1;
		for (int m = n - 1; m > i; --m)
			base *= 10;

		for (int d = 0; d < 10; ++d)
		{
			for (int j = 0; j < 128; ++j)
			{
				int64_t v1 = dp[i][j][0];
				int64_t v2 = dp[i][j][1];
				int64_t v3 = dp[i][j][2];

				int64_t v1p = v1 + base * d;
				int64_t v2p = v2 + base * d;
				int64_t v3p = v3 + base * d;

				int64_t& v1r = dp[i + 1][j + segments[d]][0];
				int64_t& v2r = dp[i + 1][j + segments[d]][1];
				int64_t& v3r = dp[i + 1][j + segments[d]][2];

				if (v1 != INT64_MAX)
					v1r = min(v1r, v1p);

				if (v2 != INT64_MAX)
				{
					int digit = (num / base) % 10;
					if (digit < d)
						v3r = min(v3r, v2p);
					else if (digit > d)
						v1r = min(v1r, v2p);
					else
						v2r = min(v2r, v2p);
				}

				if (v3 != INT64_MAX)
					v3r = min(v3r, v3p);
			}
		}
	}

	int dpi = 0;
	for (int i = 0; i < n; ++i)
		dpi += segments[input[i] - '0'];

	if (dp[n][dpi][2] < INT64_MAX)
		cout << dp[n][dpi][2] - num;
	else
		cout << min(dp[n][dpi][0], dp[n][dpi][1]) + mod - num;
}