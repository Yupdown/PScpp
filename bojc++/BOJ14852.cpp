#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1000000007;
long long memo[1 << 20]{ 1, 2 };
long long memo_sum[1 << 20]{ 1, 3 };

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		memo[i] = (memo_sum[i - 1] * 2 + memo[i - 2]) % MOD;
		memo_sum[i] = (memo_sum[i - 1] + memo[i]) % MOD;
	}

	cout << memo[n];
}