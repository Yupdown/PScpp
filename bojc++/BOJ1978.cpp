#include <iostream>

using namespace std;

int main()
{
	const int SIZEOF_CACHE = 1024;
	bool primeShive[SIZEOF_CACHE] = { true, true };

	for (int i = 2; i < SIZEOF_CACHE; i++)
	{
		if (!primeShive[i])
		{
			for (int j = i * 2; j < SIZEOF_CACHE; j += i)
				primeShive[j] = true;
		}
	}

	int n, r = 0;
	cin >> n;
	while (n-- > 0)
	{
		int m;
		cin >> m;

		if (!primeShive[m])
			r++;
	}
	cout << r << endl;
	return 0;
}