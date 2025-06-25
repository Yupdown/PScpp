#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr long long MOD = 1000000007;

template <class T>
T power_mod(T x, long long y)
{
	T ret = 1;
	while (y)
	{
		if (y & 1)
			ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

template <class T>
T mod_inverse(T x)
{
	return power_mod(x, MOD - 2);
}

template <class T>
T combination(T n, T r)
{
	T num = 1, den = 1;
	for (T k = 0; k < r; ++k)
	{
		num = num * (n - k) % MOD;
		den = den * (k + 1) % MOD;
	}
	return num * mod_inverse(den) % MOD;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long a, b, k;
		cin >> a >> b >> k;
		long long n = ((a - 1) * k + 1) % MOD;
		long long m = (combination(n, a) * k % MOD * (b - 1) + 1) % MOD;
		cout << n << " " << m << "\n";
	}
}