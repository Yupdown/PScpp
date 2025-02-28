#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	pair<int, int> lines[100000];

	for (int i = 0; i < n; i++)
		cin >> lines[i].first >> lines[i].second;

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