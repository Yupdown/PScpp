#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	cin.tie();
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	pair<int, int> lines[1000000];

	for (int i = 0; i < n; i++)
	{
		int value0, value1;
		cin >> value0 >> value1;

		lines[i].first = min(value0, value1);
		lines[i].second = max(value0, value1);
	}

	sort(lines, lines + n);
	int x = lines[0].first, y = lines[0].second, r = 0;

	for (int i = 0; i < n; i++)
	{
		if (lines[i].first > y)
		{
			r += y - x;
			x = lines[i].first;
		}
		y = max(lines[i].second, y);
	}

	cout << r + y - x << endl;

	return 0;
}