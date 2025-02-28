#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int64;

int main()
{
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<pair<int64, int64>> lines;

	for (int i = 0; i < n; i++)
	{
		int64 value0, value1;
		cin >> value0 >> value1;

		if (value0 > value1)
			lines.push_back(make_pair(value1, value0));
	}

	if (lines.size() > 0)
	{
		sort(lines.begin(), lines.end());
		int64 x = lines[0].first, y = lines[0].second, r = 0;

		for (int i = 0; i < lines.size(); ++i)
		{
			if (lines[i].first > y)
			{
				r += y - x;
				x = lines[i].first;
			}
			y = max(lines[i].second, y);
		}
		cout << m + (r + y - x) * 2 << endl;
	}
	else
		cout << m << endl;

	return 0;
}