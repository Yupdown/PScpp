#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	vector<int> isnotprime(10000001);
	isnotprime[0] = 1;
	isnotprime[1] = 1;

	for (int i = 2; i <= 10000000; ++i)
	{
		if (isnotprime[i])
			continue;
		for (int j = i * 2; j <= 10000000; j += i)
			isnotprime[j] = 1;
	}

	vector<int> primes;
	for (int i = 0; i <= 10000000; ++i)
	{
		if (!isnotprime[i])
			primes.push_back(i);
	}

	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		long long ret = 0;
		for (int p : primes)
		{
			if (p > n)
				break;
			ret += n / p;
		}
		cout << ret << "\n";
	}
}