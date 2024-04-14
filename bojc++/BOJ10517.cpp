#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

struct vector2d { double x, y; };

inline int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
	double result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	return result > 0 ? 1 : (result < 0 ? -1 : 0);
}

vector2d circumcenter(const vector2d& a, const vector2d& b)
{
	return vector2d{ (a.x + b.x) / 2, (a.y + b.y) / 2 };
}

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

int main()
{
	FASTIO();
	PRECISION(2);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti)
	{
		double rr = 0;
		vector2d points[3], p{};
		cin >> points[0].x >> points[0].y >> points[1].x >> points[1].y >> points[2].x >> points[2].y;

		for (int i = 0; i < 3; ++i)
		{
			if (sqr_dist(p, points[i]) > rr)
			{
				p = points[i];
				rr = 0;
				for (int j = 0; j < i; ++j)
				{
					if (sqr_dist(p, points[j]) > rr)
					{
						p = circumcenter(points[i], points[j]);
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

		cout << "Case #" << ti + 1 << ": " << p.x << " " << p.y << "\n";
	}
}