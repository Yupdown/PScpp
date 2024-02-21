#include <bits/stdc++.h>

using namespace std;

int table[1 << 22];
vector<int> primes;

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		if (table[i])
			continue;
		for (int j = i * 2; j <= n; j += i)
			table[j] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		if (!table[i])
			primes.push_back(i);
	}

	int cnt = 0, sum = 0;
	for (auto lhs = primes.begin(), rhs = primes.begin(); rhs != primes.end(); ++rhs)
	{
		sum += *rhs;
		while (lhs <= rhs && sum > n)
			sum -= *(lhs++);
		if (sum == n)
			++cnt;
	}

	cout << cnt;
}