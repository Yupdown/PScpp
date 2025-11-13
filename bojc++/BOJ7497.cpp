#include <bits/stdc++.h>

using namespace std;

long long product(long long n)
{
	long long ret = 1;
	while (n > 0)
	{
		if (n % 10 > 0)
			ret *= n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	long long n;
	cin >> n;

	long long ret = product(n);
	for (long long d = 1; d <= n; d *= 10)
	{
		long long digit = (n / d) % 10;
		if (digit < 9)
		{
			n -= (digit + 1) * d;
			if (n < 0)
				break;
			ret = max(ret, product(n));
		}
	}
	cout << ret;
}