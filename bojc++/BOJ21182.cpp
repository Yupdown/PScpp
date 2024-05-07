#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

struct vector2d { double x, y; };
array<double, 3> table[5000];
vector2d points[5000];

vector2d circumcenter(const vector2d& a, const vector2d& b, const vector2d& c)
{
	double ax = a.x - c.x;
	double ay = a.y - c.y;
	double bx = b.x - c.x;
	double by = b.y - c.y;

	double asq = ax * ax + ay * ay;
	double bsq = bx * bx + by * by;
	double ccw = ax * by - ay * bx;

	return vector2d{
		c.x + (by * asq - ay * bsq) / (ccw * 2),
		c.y + (-bx * asq + ax * bsq) / (ccw * 2)
	};
}

double sqr_dist(const vector2d& lhs, const vector2d& rhs)
{
	vector2d dv = vector2d{ lhs.x - rhs.x, lhs.y - rhs.y };
	return dv.x * dv.x + dv.y * dv.y;
}

double solution(int n)
{
	vector2d p{};
	double rr = 0;

	for (int i = 0; i < n; ++i)
	{
		if (sqr_dist(p, points[i]) > rr)
		{
			p = points[i];
			rr = 0;
			for (int j = 0; j < i; ++j)
			{
				if (sqr_dist(p, points[j]) > rr)
				{
					p = vector2d{ (points[i].x + points[j].x) / 2, (points[i].y + points[j].y) / 2 };
					rr = sqr_dist(p, points[i]);
					for (int k = 0; k < j; ++k)
					{
						if (sqr_dist(p, points[k]) > rr)
						{
							p = circumcenter(points[i], points[j], points[k]);
							rr = sqr_dist(p, points[i]);
						}
					}
				}
			}
		}
	}

	return rr;
}

int main()
{
	FASTIO();
	PRECISION(10);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i][0] >> table[i][1] >> table[i][2];
	for (int i = 0; i < n; ++i)
		swap(table[i], table[rand() % n]);

	double rr = 1e+8;
	transform(table, table + n, points, [](const auto& v) { return vector2d{ v[0], v[1] }; });
	rr = min(rr, solution(n));
	transform(table, table + n, points, [](const auto& v) { return vector2d{ v[0], v[2] }; });
	rr = min(rr, solution(n));
	transform(table, table + n, points, [](const auto& v) { return vector2d{ v[1], v[2] }; });
	rr = min(rr, solution(n));

	cout << sqrt(rr) * 2;
}