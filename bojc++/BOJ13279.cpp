#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr long long MOD = 100003;
long long table[30000];
long long memo[2][30000];

int main()
{
	FASTIO();

	int n, q;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	for (int i = 0; i < n; ++i)
	{
		memo[i & 1][0] = (memo[~i & 1][0] + table[i]) % MOD;
		for (int j = 1; j <= i; ++j)
			memo[i & 1][j] = (memo[~i & 1][j] + memo[~i & 1][j - 1] * table[i]) % MOD;
	}
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int v;
		cin >> v;
		cout << memo[~n & 1][v - 1] << '\n';
	}
}