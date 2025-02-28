#include <iostream>
#include <cmath>

using namespace std;

double get_function(double a, double b, double x)
{
	return a * pow(M_E, -(x * x)) + b * sqrt(x);
}

double get_circle_size(double r)
{
	return r * r * M_PI;
}

int main()
{
	const int SAMPLE_COUNT = 1048576;

	int n, ir = 0;
	double v;
	cin >> v >> n;

	double dv[10];
	for (int i = 0; i < n; ++i)
	{
		double a, b, h;
		cin >> a >> b >> h;

		double vi = 0.0;
		for (int i = 0; i < SAMPLE_COUNT; ++i)
		{
			double dx = h / SAMPLE_COUNT;
			double x = dx * (0.5 + i);
			double r = get_function(a, b, x);
			vi += get_circle_size(r) * dx;
		}

		dv[i] = abs(vi - v);
		if (dv[i] < dv[ir])
			ir = i;
	}

	cout << ir << endl;
	return 0;
}