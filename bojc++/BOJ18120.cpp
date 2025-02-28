#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double get_max(double a, double b, double c, double xmin)
{
	double alpha = max(-b / (a * 2.0), xmin);
	return a * alpha * alpha + b * alpha + c;
}

double get_max(double a, double b, double c, double xmin, double xmax)
{
	double alpha = max(min(-b / (a * 2.0), xmax), xmin);
	return a * alpha * alpha + b * alpha + c;
}

int main()
{
	cout.precision(8);
	cout << fixed;

	int n, a;
	pair<double, int> dw[100000];

	cin >> n >> a;
	for (int i = 0; i < n; ++i)
	{
		int xi, yi;
		cin >> xi >> yi >> dw[i].second;
		dw[i].first = sqrt(xi * xi + yi * yi);
	}

	sort(dw, dw + n);

	double wmax = 0.0, b = 0.0, c = 0.0;
	for (int i = 0; i < n; ++i)
	{
		double m = b + dw[i].second;
		c = c + (b - m) * dw[i].first;
		b = m;

		if (i < n - 1)
			wmax = max(get_max(-a, b, c, dw[i].first, dw[i + 1].first), wmax);
		else
			wmax = max(get_max(-a, b, c, dw[i].first), wmax);
	}

	cout << wmax << endl;
	return 0;
}