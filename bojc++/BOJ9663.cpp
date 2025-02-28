#include <iostream>
#include <stack>

using namespace std;

int map[14];

int function(int n, int y)
{
	int result = 0;

	if (y >= n)
		return 1;

	for (int x = 0; x < n; x++)
	{
		if (map[y] & (1 << x))
			continue;

		int region[14];
		for (int i = y + 1; i < n; i++)
		{
			int row = 0;
			row |= 1 << x;
			if (x - (i - y) >= 0)
				row |= 1 << x - (i - y);
			if (x + (i - y) < n)
				row |= 1 << x + (i - y);

			row &= ~map[i];
			map[i] |= row;
			region[i] = row;
		}

		result += function(n, y + 1);

		for (int i = y + 1; i < n; i++)
			map[i] &= ~region[i];
	}

	return result;
}

int main()
{
	int n;
	cin >> n;
	cout << function(n, 0) << endl;
	return 0;
}