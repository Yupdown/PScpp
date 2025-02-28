#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int a[500000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int sum = 0, count = 0, maxCount = 0, current = 0;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];

		if (a[i] == a[i - count])
			count++;
		else
			count = 1;

		if (count > maxCount)
		{
			maxCount = count;
			current = a[i];
			flag = true;
		}
		else if (count == maxCount)
		{
			if (flag)
			{
				current = a[i];
				flag = false;
			}
		}
	}

	cout
		<< (int)round((double)sum / n) << endl
		<< a[n / 2] << endl
		<< current << endl
		<< a[n - 1] - a[0] << endl;
	return 0;
}