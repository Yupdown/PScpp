#include <iostream>

using namespace std;

int main()
{
	const int SIZEOF_CACHE = 300000;
	bool primeShive[SIZEOF_CACHE] = { false };

	for (int i = 2; i < SIZEOF_CACHE; i++)
	{
		if (!primeShive[i])
		{
			for (int j = i * 2; j < SIZEOF_CACHE; j += i)
				primeShive[j] = true;
		}
	}

	int n, r;
	cin >> n;
	while (n > 0)
	{
		r = 0;
		for (int i = n + 1; i <= n * 2; i++)
		{
			if (!primeShive[i])
				r++;
		}
		cout << r << endl;
		cin >> n;
	}

	return 0;
}