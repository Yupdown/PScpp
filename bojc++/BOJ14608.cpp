#include <iostream>
#include <cmath>

using namespace std;

double function_y(int k, const int c[10], double x)
{
	double result = 0.0;
	for (int i = 0; i < k + 1; ++i)
		result += pow<double>(x, k - i) * c[i];
	return result;
}

double integral(int k, const int c[10], int a, int b)
{
	double result = 0.0;
	for (int i = 0; i < k + 1; ++i)
	{
		int n = k + 1 - i;
		result += (pow<double>(b, n) - pow<double>(a, n)) * c[i] / n;
	}
	return result;
}

double binary_search(double min, double max, bool (*pred)(double))
{
	double x = min;
	for (double dx = max - min; dx >= 1e-12; dx *= 0.5)
	{
		if (pred(x + dx))
			x += dx;
	}
	return x;
}

double riemann_sum(int k, const int c[10], int a, int b, int n, double e)
{
	double result = 0.0;
	double dx = double(b - a) / n;
	for (int i = 0; i < n; ++i)
		result += function_y(k, c, dx * i + e + a) * dx;
	return result;
}

int main()
{
	static int k;
	static int c[11];
	static int a, b, n;

	cin >> k;
	for (int i = 0; i < k + 1; ++i)
		cin >> c[i];
	cin >> a >> b >> n;

	static double t = integral(k, c, a, b);
	cout << binary_search(0.0, double(b - a) / n, [](double v) -> bool { return riemann_sum(k, c, a, b, n, v) <= t; }) << endl;

	return 0;
}