#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

bool che[1 << 15];
vector<long long> primes;
using iter_t = set<long long>::const_iterator;

long long get_factor(long long n)
{
	for (auto prime : primes)
	{
		if (prime * prime > n)
			return n;
		if (n % prime == 0)
			return prime;
	}
	return n;
}

long long solution(long long a, long long b, long long i, long long v, iter_t iter, iter_t end)
{
	if (iter == end)
	{
		if (v == 1)
			return 0;
		long long r = b / v - (a - 1) / v;
		return i & 1 ? r : -r;
	}
	return solution(a, b, i + 1, v * *iter, next(iter), end) + solution(a, b, i, v, next(iter), end);
}

int main()
{
	FASTIO();

	for (int i = 2; i < 1 << 15; ++i)
	{
		if (che[i])
			continue;
		for (int j = i * 2; j < 1 << 15; j += i)
			che[j] = true;
	}
	for (int i = 2; i < 1 << 15; ++i)
	{
		if (!che[i])
			primes.push_back(i);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long long a, b, n;
		cin >> a >> b >> n;
		set<long long> factors;
		while (n > 1)
		{
			long long v = get_factor(n);
			factors.insert(v);
			n /= v;
		}
		long long r = b - a + 1 - solution(a, b, 0, 1, factors.begin(), factors.end());
		cout << "Case #" << i + 1 << ": " << r << "\n";
	}
}