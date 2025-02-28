#include <iostream>

using namespace std;

int main()
{
	const int SIZEOF_CACHE = 100;

	long long p[SIZEOF_CACHE] = { 1, 1, 1, 2, 2 };

	for (int i = 5; i < SIZEOF_CACHE; i++)
		p[i] = p[i - 5] + p[i - 1];

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;
		cout << p[n - 1] << endl;
	}

	return 0;
}