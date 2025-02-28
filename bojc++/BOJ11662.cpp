#include <iostream>
#include <cmath>

using namespace std;

double lerp(double a, double b, double t)
{
	return a + (b - a) * t;
}

double distance(double ax, double ay, double bx, double by)
{
	double dx = bx - ax;
	double dy = by - ay;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	double ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	double lo = 0.0, hi = 1.0;
	double p, q;

	while (hi - lo > 1.e-12)
	{
		p = (lo * 2.0 + hi) / 3.0;
		q = (lo + hi * 2.0) / 3.0;

		double dp = distance(lerp(ax, bx, p), lerp(ay, by, p), lerp(cx, dx, p), lerp(cy, dy, p));
		double dq = distance(lerp(ax, bx, q), lerp(ay, by, q), lerp(cx, dx, q), lerp(cy, dy, q));

		if (dp < dq)
			hi = q;
		else
			lo = p;
	}

	cout.precision(10);
	cout << fixed;
	cout << distance(lerp(ax, bx, lo), lerp(ay, by, lo), lerp(cx, dx, lo), lerp(cy, dy, lo)) << endl;
	return 0;
}