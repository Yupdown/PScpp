#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
typedef long long int64;

struct vector2d
{
	int64 x;
	int64 y;

	struct greater_y
	{
		bool operator() (const vector2d& a, const vector2d& b) const
		{
			return a.y == b.y ? a.x < b.x : a.y < b.y;
		}
	};
};

int64 sqr_distance(const vector2d& from, const vector2d& to)
{
	int64 dx = from.x - to.x;
	int64 dy = from.y - to.y;
	return dx * dx + dy * dy;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector2d points[500000];
	for (int i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y;

	sort(points, points + n, [](const vector2d& a, const vector2d& b) -> bool { return a.x < b.x; });

	int64 distance_min = sqr_distance(points[0], points[1]);

	set<vector2d, vector2d::greater_y> point_set;
	point_set.insert(points[0]);
	point_set.insert(points[1]);

	for (int i = 2, j = 0; i < n; ++i)
	{
		int64 sqrt_distance_min = ceil(sqrt(distance_min));

		while (j < i)
		{
			if (points[i].x - points[j].x <= sqrt_distance_min)
				break;

			point_set.erase(points[j++]);
		}

		auto iterator = point_set.lower_bound({ 0, points[i].y - sqrt_distance_min });
		auto end = point_set.upper_bound({ 0, points[i].y + sqrt_distance_min });

		while (iterator != end)
			distance_min = min(distance_min, sqr_distance(points[i], *iterator++));

		point_set.insert(points[i]);
	}

	cout << distance_min << endl;
	return 0;
}