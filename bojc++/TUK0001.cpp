#include <bits/stdc++.h>

using namespace std;

const int SIZEOF_CACHE = 1'048'576;
bool primeShive[SIZEOF_CACHE] = { true, true };

int main()
{
	for (int i = 2; i < SIZEOF_CACHE; i++)
	{
		if (!primeShive[i])
		{
			for (int j = i * 2; j < SIZEOF_CACHE; j += i)
				primeShive[j] = true;
		}
	}

	int n;
	cin >> n;
	int m = n;

	do
	{
		if (primeShive[m] || !(m % 10))
			continue;
		
		int x = m;
		int y = 0;

		while (x > y)
		{
			y = y * 10 + x % 10;
			x = x / 10;
		}

		if (x == y || x == y / 10)
			break;

	} while (++m < SIZEOF_CACHE);

	cout << m << endl;
}