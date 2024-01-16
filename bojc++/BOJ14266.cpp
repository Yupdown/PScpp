#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<pair<int64_t, int64_t>, int> points[200000];

int64_t orientation(int64_t ax, int64_t ay, int64_t bx, int64_t by, int64_t cx, int64_t cy)
{
	return (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		pair<int64_t, int64_t> p1, p2;
		cin >> p1.first >> p1.second >> p2.first >> p2.second;

		if (orientation(0, 0, p1.first, p1.second, p2.first, p2.second) < 0)
			swap(p1, p2);

		points[i * 2] = make_pair(p1, 1);
		points[i * 2 + 1] = make_pair(p2, -1);
	}

	sort(points, points + n * 2, [](const pair<pair<int64_t, int64_t>, int>& lhs, const pair<pair<int64_t, int64_t>, int>& rhs)
		{
			int64_t result = orientation(0, 0, lhs.first.first, lhs.first.second, rhs.first.first, rhs.first.second);
			if (result == 0)
				return lhs.second > rhs.second;
			return result > 0;
		});

	int value = 0;
	int value_max = 0;
	for (int i = 0; i < n * 2; ++i)
	{
		value += points[i].second;
		value_max = max(value_max, value);
	}

	cout << value_max;
}