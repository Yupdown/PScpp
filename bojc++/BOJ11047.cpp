#include <iostream>

using namespace std;

int main()
{
	int n, k;
	int a[10];

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int unit = a[n - (i + 1)];

		if (k >= unit)
		{
			result += k / unit;
			k %= unit;
		}
	}

	cout << result << endl;
	return 0;
}