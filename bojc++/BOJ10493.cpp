#include <iostream>
#include <cmath>

using namespace std;

double cubic_function(double a0, double a1, double a2, double a3, double x)
{
	return a0 + a1 * x + a2 * x * x + a3 * x * x * x;
}

double clamp01(double x)
{
	return x > 1.0 ? 1.0 : x < 0.0 ? 0.0 : x;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(10);

	double b0, b1, b2, b3;
	double t0, t1, t2, t3;

	while (cin >> b0 >> b1 >> b2 >> b3 >> t0 >> t1 >> t2 >> t3)
	{
		double a0 = t0 - b0;
		double a1 = t1 - b1;
		double a2 = t2 - b2;
		double a3 = t3 - b3;

		double v[4];

		double disc = a2 * a2 - a1 * a3 * 3.0;
		double x0, x1;
		if (disc < 0.0)
		{
			x0 = 0.0;
			x1 = 1.0;
		}
		else
		{
			x0 = clamp01((-a2 - sqrt(disc)) / (a3 * 3.0));
			x1 = clamp01((-a2 + sqrt(disc)) / (a3 * 3.0));
		}

		v[0] = cubic_function(a0, a1, a2, a3, 0.0);
		v[1] = cubic_function(a0, a1, a2, a3, x0);
		v[2] = cubic_function(a0, a1, a2, a3, x1);
		v[3] = cubic_function(a0, a1, a2, a3, 1.0);

		double minv = v[0];
		double maxv = v[0];

		for (int i = 1; i < 4; ++i)
		{
			minv = min(minv, v[i]);
			maxv = max(maxv, v[i]);
		}

		cout << maxv - minv << endl;
	}

	return 0;
}