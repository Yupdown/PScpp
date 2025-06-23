#include <bits/stdc++.h>

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
T factorial_mod(T x)
{
	T ret = 1;
	while (x > 1)
		ret = ret * x-- % MOD;
	return ret;
}

template <class T>
T combination(T n, T r)
{
	return factorial_mod(n) * mod_inverse(factorial_mod(r) * factorial_mod(n - r) % MOD) % MOD;
}

int main()
{
	long long n, k;
	cin >> n >> k;
	cout << combination(n, k);
}