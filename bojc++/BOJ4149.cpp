#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = __int128;

int64 table[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };

int64 power(int64 x, int64 y, int64 mod)
{
	if (y <= 1)
		return x % mod;
	int64 xp = power(x, y / 2, mod);
	if (y & 1)
		return x * xp * xp % mod;
	else
		return xp * xp % mod;
}

int64 gcd(int64 lhs, int64 rhs)
{
	if (lhs < rhs)
		swap(lhs, rhs);
	while (rhs != 0)
	{
		int64 temp = lhs;
		lhs = rhs;
		rhs = temp % rhs;
	}
	return lhs;
}

bool miller_rabin(int64 n, int64 a)
{
	int64 s = 0;
	int64 d = n - 1;
	while (d % 2 == 0)
	{
		s += 1;
		d /= 2;
	}
	int64 x = power(a, d, n);
	if (x == 1 || x + 1 == n)
		return true;
	for (int64 i = 0; i < s - 1; ++i)
	{
		x = power(x, 2, n);
		if (x + 1 == n)
			return true;
	}
	return false;
}

bool is_prime(int64 n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	if (find(begin(table), end(table), n) != end(table))
		return true;
	for (int64 a : table)
	{
		if (!miller_rabin(n, a))
			return false;
	}
	return true;
}

void pollard_rho(int64 n, vector<int64>& out)
{
	if (is_prime(n))
	{
		out.push_back(n);
		return;
	}
	if (n % 2 == 0)
	{
		out.push_back(2);
		pollard_rho(n / 2, out);
		return;
	}
	int64 x = rand() * rand() % (n - 2) + 2;
	int64 c = rand() * rand() % (n - 1) + 1;
	int64 y = x;
	int64 d;
	do
	{
		x = (x * x + c) % n;
		y = (y * y + c) % n;
		y = (y * y + c) % n;
		d = gcd(abs(x - y), n);
	} while (d == 1);
	if (d == n)
		pollard_rho(n, out);
	else
	{
		pollard_rho(d, out);
		pollard_rho(n / d, out);
	}
}

int main()
{
	long long n;
	cin >> n;
	vector<int64> primes;
	pollard_rho(n, primes);
	sort(primes.begin(), primes.end());
	for (int64 prime : primes)
		cout << static_cast<long long>(prime) << '\n';
}