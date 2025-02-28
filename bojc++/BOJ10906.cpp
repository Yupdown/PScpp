#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	pair<int, int> se0[11], se1[11];

	for (int i = 0; i < n; i++)
		cin >> se0[i].first >> se0[i].second;
	for (int i = 0; i < n; i++)
		cin >> se1[i].first >> se1[i].second;

	int r = -n;
	for (int i = 0; i < n; i++)
	{
		int d0 = se0[i].first - se1[i].second;
		int d1 = se0[i].second - se1[i].first;

		if (d0 == 0 || d1 == 0)
			r += 1;
		else if (d0 * d1 < 0)
			r += 2;
		else
		{
			r = -1;
			break;
		}
	}

	cout << r << endl;
	return 0;
}