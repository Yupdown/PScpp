#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[201];
int memo[201];

int main()
{
	FASTIO();

	int n, s, t;
	while ((cin >> n) && n)
	{
		cin >> s >> t;
		fill(begin(table), end(table), 0);
		fill(begin(memo), end(memo), -100'000'000);
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		for (int i = 0; i < s; ++i)
			memo[i] = table[i];
		for (int i = 1; i < t; ++i)
		{
			for (int j = n; j >= 0; --j)
			{
				for (int k = 1; k <= s && j - k >= 0; ++k)
					memo[j] = max(memo[j], memo[j - k] + table[j]);
			}
		}
		cout << memo[n] << "\n";
	}
}