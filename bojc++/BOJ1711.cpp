#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

struct vector2d
{
	int64 x;
	int64 y;
};

bool right_triangle(const vector2d& p1, const vector2d& p2, const vector2d& p3)
{
	int64 dx1 = p1.x - p2.x;
	int64 dx2 = p2.x - p3.x;
	int64 dx3 = p3.x - p1.x;
	int64 dy1 = p1.y - p2.y;
	int64 dy2 = p2.y - p3.y;
	int64 dy3 = p3.y - p1.y;

	int64 a2 = dx1 * dx1 + dy1 * dy1;
	int64 b2 = dx2 * dx2 + dy2 * dy2;
	int64 c2 = dx3 * dx3 + dy3 * dy3;

	return max(max(a2, b2), c2) * 2 == a2 + b2 + c2;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	vector2d points[1500];
	for (int i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y;

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
				count += right_triangle(points[i], points[j], points[k]);
		}
	}

	cout << count;
	return 0;
}