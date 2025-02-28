#include <iostream>
#include <cmath>

using namespace std;

double get_volume(int n, double a[11], double xa, double xb)
{
	double y = 0.0;
	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			int d = i + j + 1;
			y += a[i] * a[j] * (pow(xb, d) - pow(xa, d)) / d;
		}
	}
	return y * M_PI;
}

int main()
{
	cout.precision(2);
	cout << fixed;

	int n, nc = 0;
	double a[11], xmin, xmax, inc;

	while (cin >> n)
	{
		for (int i = 0; i < n + 1; ++i)
			cin >> a[i];
		cin >> xmin >> xmax >> inc;

		double v = get_volume(n, a, xmin, xmax);
		cout << "Case " << ++nc << ": " << v << endl;

		int i = 0;
		while (i < 8)
		{
			double tv = inc * (i + 1);
			if (tv > v)
				break;

			double x = xmin;
			for (double dx = xmax - xmin; dx > 1.0e-8; dx *= 0.5)
			{
				if (get_volume(n, a, xmin, x + dx) <= tv)
					x += dx;
			}
			cout << x - xmin << ' ';
			++i;
		}

		if (i == 0)
			cout << "insufficient volume";
		cout << endl;
	}

	return 0;
}