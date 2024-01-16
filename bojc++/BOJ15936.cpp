#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long ll;

const ll MOD = 100003;
ll fact[1 << 17];

ll powmod(ll a, ll b, ll p)
{
	a %= p;
	if (a == 0)
		return 0;
	ll product = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			product *= a;
			product %= p;
			--b;
		}
		a *= a;
		a %= p;
		b /= 2;
	}
	return product;
}

ll inv(ll a, ll p)
{
	return powmod(a, p - 2, p);
}

ll get_value(ll n, ll k, ll i, ll p)
{
	return ((fact[n] * inv(fact[i], p) % p) * inv(fact[n - k - i], p)) % p;
}

int main()
{
	FASTIO();

	fact[0] = 1;
	for (int i = 1; i < (1 << 17); ++i)
		fact[i] = (fact[i - 1] * i) % MOD;

	int n, m, k;
	cin >> n >> m >> k;

	int a = m;
	int b = m;

	for (int i = 0; i < 30; ++i)
	{
		if (a == m && a & 1 << i)
			a -= 1 << i;
		if (b == m && !(b & 1 << i))
			b += 1 << i;
	}

	cout << a << '\n';
	cout << b << '\n';
	ll c = 0;
	for (int i = 0; i <= n - k; ++i)
		c = (c + get_value(n, k, i, MOD)) % MOD;
	cout << c << '\n';
}