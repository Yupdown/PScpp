#include <iostream>
#include <cmath>
#include <set>

using namespace std;
typedef long long int64;

int64 euler_phi(int64 n)
{
	set<int64> prime_set;
	int64 result = n;

	while (n > 1)
	{
		int64 prime = 2;
		int64 end = sqrt(n) + 1;

		while (prime < end)
		{
			if (n % prime == 0)
				break;
			prime++;
		}

		if (prime >= end)
			prime = n;
		n /= prime;

		if (prime_set.find(prime) != prime_set.end())
			continue;

		result = result / prime * (prime - 1);
		prime_set.insert(prime);
	}

	return result;
}

int main()
{
	int64 n;
	cin >> n;

	cout << euler_phi(n) << endl;
	return 0;
}