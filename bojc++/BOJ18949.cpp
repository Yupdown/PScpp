#include <bits/stdc++.h>
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	PRECISION(10);

	double a;
	cin >> a;

	double x0 = a + (1 - sqrt(a * 4 + 1)) / 2;
	double x2 = a + (1 + sqrt(a * 4 + 1)) / 2;

	double xf = a;
	double xt = x2;
	while (xt - xf > 1e-12)
	{
		double xm = (xf + xt) / 2;
		if (a - sqrt(xm) > pow(xm - a, 2))
			xf = xm;
		else
			xt = xm;
	}
	double x1 = (xf + xt) / 2;

	double s = 0;
	s += pow(x1, 2) / 2 + pow(x1, 1.5) * 2 / 3 - x1 * a;
	s -= pow(x0, 2) / 2 + pow(x0, 1.5) * 2 / 3 - x0 * a;
	s += -pow(x2, 3) / 3 + pow(x2, 2) * (2 * a + 1) / 2 - x2 * a * a;
	s -= -pow(x1, 3) / 3 + pow(x1, 2) * (2 * a + 1) / 2 - x1 * a * a;

	cout << s * 2;
}