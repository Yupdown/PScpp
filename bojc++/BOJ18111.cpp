#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

int main()
{
	int n, m, b;
	cin >> n >> m >> b;

	int height[250000];

	int valley = 256;
	for (int i = 0; i < n * m; i++)
	{
		int value;
		cin >> value;
		height[i] = value;
		valley = min(valley, value);
	}

	int result = INT_MAX;
	int h = valley;
	for (; h <= 256; h++)
	{
		int t = 0;
		int rb = b;

		for (int i = 0; i < n * m; i++)
		{
			int gap = height[i] - h;

			rb += gap;
			t += gap > 0 ? gap * 2 : -gap;
		}

		if (rb < 0 || t > result)
			break;

		result = t;
	}

	cout << result << ' ' << h - 1 << endl;
	return 0;
}