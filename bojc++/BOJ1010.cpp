#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m, r = 1;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			r *= m - i;
			r /= i + 1;
		}

		cout << r << endl;
	}

	return 0;
}