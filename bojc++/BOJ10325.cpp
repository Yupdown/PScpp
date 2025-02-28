#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, r = 0;
		double tmax[10];
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;

			tmax[i] = (double)(b * b) / (a * 4) + c;
			if (tmax[i] > tmax[r])
				r = i;
		}

		cout << r + 1 << endl;
	}

	return 0;
}