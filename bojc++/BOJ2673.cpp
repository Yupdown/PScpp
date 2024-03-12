#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100][100];
int memo[100][100];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int lhs, rhs;
		cin >> lhs >> rhs;
		table[lhs - 1][rhs - 1] = 1;
		table[rhs - 1][lhs - 1] = 1;
	}

	for (int j = 0; j < 100; ++j)
	{
		for (int i = j; i >= 0; --i)
		{
			for (int k = i; k < j; ++k)
				memo[i][j] = max(memo[i][j], memo[i][k] + memo[k][j] + table[i][j]);
		}
	}

	cout << memo[0][99];
}