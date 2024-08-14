#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long memo[5001][5002];

int main()
{
	FASTIO();

	memo[0][0] = 1;
	for (int i = 1; i <= 5000; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			memo[i][j] = memo[i - 1][j + 1];
			if (j > 0)
				memo[i][j] += memo[i - 1][j - 1];
			memo[i][j] %= 1000000007;
		}
	}

	int t;
	cin >> t;

	while (t--)
	{
		int l;
		cin >> l;
		cout << memo[l][0] << '\n';
	}
}