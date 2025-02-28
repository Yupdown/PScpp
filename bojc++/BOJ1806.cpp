#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;

	int a[100000];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int lo = 0, hi = 1;
	int sum = a[0];
	int result = n + 1;

	while (hi < n + 1)
	{
		if (sum < s)
			sum += a[hi++];
		else
		{
			result = min(result, hi - lo);
			sum -= a[lo++];
		}
	}

	cout << (result > n ? 0 : result) << endl;
	return 0;
}