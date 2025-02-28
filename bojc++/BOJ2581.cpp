#include <iostream>

using namespace std;

int main()
{
	const int SIZEOF_CACHE = 16384;
	bool primeShive[SIZEOF_CACHE] = { true, true };

	for (int i = 2; i < SIZEOF_CACHE; i++)
	{
		if (!primeShive[i])
		{
			for (int j = i * 2; j < SIZEOF_CACHE; j += i)
				primeShive[j] = true;
		}
	}

	int m, n;
	cin >> m >> n;

	int sum = 0, min = 0;
	for (int i = m; i <= n; i++)
	{
		if (!primeShive[i])
		{
			sum += i;
			min = min > 0 ? min : i;
		}
	}

	if (min > 0)
		cout << sum << endl << min << endl;
	else
		cout << -1 << endl;
	return 0;
}