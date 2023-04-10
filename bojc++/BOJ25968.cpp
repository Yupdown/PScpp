#include <bits/stdc++.h>
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int n;
double a[11];

inline double function_y(double x)
{
	double y = 0;
	double powx = 1;
	for (int i = n; i >= 0; --i, powx *= x * x)
		y += a[i] * powx;
	return y;
}

int main()
{
	PRECISION(4);

	int k;
	cin >> n;
	for (int i = 0; i < n + 1; ++i)
		cin >> a[i];
	cin >> k;

	double x0 = 0;
	for (double dx = 32; dx > 1e-12; dx /= 2)
	{
		if (function_y(x0 + dx) * a[n] >= 0)
			x0 += dx;
	}

	double r = 0.0;
	for (int i = 0; i < k / 2; ++i)
		r += function_y((i * 2 + 1) * x0 / k);

	cout << abs(r * x0 * 4 / k);
}