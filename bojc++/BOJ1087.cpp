#include <iostream>
#include <cmath>

using namespace std;

double function(int n, int* px, int* py, int* vx, int* vy, double t)
{
	double minx, miny;
	double maxx, maxy;

	for (int i = 0; i < n; ++i)
	{
		double x = t * vx[i] + px[i];
		double y = t * vy[i] + py[i];

		if (i > 0)
		{
			minx = min(minx, x);
			miny = min(miny, y);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
		}
		else
		{
			minx = x;
			miny = y;
			maxx = x;
			maxy = y;
		}
	}

	return max(maxx - minx, maxy - miny);
}

int main()
{
	int n, px[50], py[50], vx[50], vy[50];
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> px[i] >> py[i] >> vx[i] >> vy[i];

	double lo = 0.0, hi = 2000.0;

	while (hi - lo > 1.e-12)
	{
		double p = (lo * 2.0 + hi) / 3.0;
		double q = (lo + hi * 2.0) / 3.0;

		double dp = function(n, px, py, vx, vy, p);
		double dq = function(n, px, py, vx, vy, q);

		if (dp < dq)
			hi = q;
		else
			lo = p;
	}

	cout.precision(10);
	cout << fixed;
	cout << function(n, px, py, vx, vy, lo) << endl;
	return 0;
}