#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[3333][5];
const int modulo = 1000000007;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		if (n % 3)
		{
			cout << "0\n";
			continue;
		}
		else
			n /= 3;

		memset(memo, 0, sizeof(memo));

		memo[0][0] = 3;
		memo[0][1] = 1;
		memo[0][2] = 1;
		memo[0][3] = 1;
		memo[0][4] = 1;

		for (int i = 1; i < n; ++i)
		{
			memo[i][1] = (memo[i - 1][1] + memo[i - 1][0]) % modulo;
			memo[i][3] = (memo[i - 1][3] + memo[i - 1][0]) % modulo;
			memo[i][2] = (memo[i - 1][2] + memo[i][1]) % modulo;
			memo[i][4] = (memo[i - 1][4] + memo[i][3]) % modulo;
			memo[i][0] = (memo[i][2] + memo[i][4]) % modulo;
			memo[i][0] = (memo[i - 1][0] + memo[i][0]) % modulo;
		}

		cout << memo[n - 1][0] << '\n';
	}

	return 0;
}