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

template <class T>
T combination(T n, T r)
{
	return factorial_mod(n) * mod_inverse(factorial_mod(r) * factorial_mod(n - r) % MOD) % MOD;
}