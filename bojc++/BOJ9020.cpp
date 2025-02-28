#include <iostream>

using namespace std;

int main()
{
	const int SIZEOF_CACHE = 16384;
	bool primeShive[SIZEOF_CACHE] = { false };

	for (int i = 2; i < SIZEOF_CACHE; i++)
	{
		if (!primeShive[i])
		{
			for (int j = i * 2; j < SIZEOF_CACHE; j += i)
				primeShive[j] = true;
		}
	}

	int t, n;
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		for (int i = 0; i <= n / 2; i++)
		{
			int a = n / 2 - i;
			int b = n / 2 + i;

			if (!primeShive[a] && !primeShive[b])
			{
				cout << a << ' ' << b << endl;
				break;
			}
		}
	}

	return 0;
}