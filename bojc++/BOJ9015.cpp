#include <iostream>
#include <set>

#define RANGEOF_X 65536

using namespace std;
typedef pair<int, int> vector2d;

vector2d point_list[3000];
set<int> point_sets[RANGEOF_X];

bool contains(const vector2d& _Keyval)
{
	set<int> set = point_sets[_Keyval.first + RANGEOF_X / 2];
	return set.find(_Keyval.second) != set.end();
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> point_list[i].first >> point_list[i].second;
			point_sets[point_list[i].first + RANGEOF_X / 2].insert(point_list[i].second);
		}

		int dist_max = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				vector2d v0 = point_list[i];
				vector2d v1 = point_list[j];

				int dx = v1.first - v0.first;
				int dy = v1.second - v0.second;

				if ((dx + dy) % 2 != 0)
					continue;
				if (dx * dx + dy * dy <= dist_max)
					continue;

				bool c0 = contains({ v0.first + (dx - dy) / 2, v0.second + (dy + dx) / 2 });
				bool c1 = contains({ v0.first + (dx + dy) / 2, v0.second + (dy - dx) / 2 });

				if (c0 && c1)
					dist_max = dx * dx + dy * dy;
			}
		}

		cout << dist_max / 2 << endl;
		for (int i = 0; i < RANGEOF_X; ++i)
			point_sets[i].clear();
	}

	return 0;
}