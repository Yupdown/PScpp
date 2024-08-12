#include <bits/stdc++.h>

using namespace std;

int table[300];
int memo[300][2];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	memo[0][0] = memo[0][1] = table[0];
	for (int i = 1; i < n; ++i)
	{
		memo[i][0] = table[i];
		if (i > 1)
			memo[i][0] += max(memo[i - 2][0], memo[i - 2][1]);
		memo[i][1] = memo[i - 1][0] + table[i];
	}

	cout << max(memo[n - 1][0], memo[n - 1][1]);
}