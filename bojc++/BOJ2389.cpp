#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

struct vector2d { double x, y; };
vector2d table[100];

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
	PRECISION(10);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i].x >> table[i].y;
	for (int i = 0; i < n; ++i)
		swap(table[i], table[rand() % n]);

	vector2d p;
	double rr = 0;

	for (int i = 0; i < n; ++i)
	{
		if (sqr_dist(p, table[i]) > rr)
		{
			p = table[i];
			rr = 0;
			for (int j = 0; j < i; ++j)
			{
				if (sqr_dist(p, table[j]) > rr)
				{
					p = vector2d{ (table[i].x + table[j].x) / 2, (table[i].y + table[j].y) / 2 };
					rr = sqr_dist(p, table[i]);
					for (int k = 0; k < j; ++k)
					{
						if (sqr_dist(p, table[k]) > rr)
						{
							p = circumcenter(table[i], table[j], table[k]);
							rr = sqr_dist(p, table[i]);
						}
					}
				}
			}
		}
	}

	cout << p.x << ' ' << p.y << ' ' << sqrt(rr);
}