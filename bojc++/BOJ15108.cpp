#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

inline double formula(double x, double v, double s, double t)
{
	return x * tan(t) + s / v / cos(t);
}

int main()
{
	FASTIO();
	PRECISION(3);

	int n;
	double x, v, li, ri, vi;
	cin >> n >> x >> v;
	double s = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> li >> ri >> vi;
		s += (ri - li) * vi;
	}

	double p = -M_PI_2;
	double q = M_PI_2;

	if (formula(x, v, s, p) * formula(x, v, s, q) > 0)
		cout << "Too hard";
	else
	{
		while (q - p > 1e-12)
		{
			double m = (p + q) / 2;
			if (formula(x, v, s, m) < 0)
				p = m;
			else
				q = m;
		}
		cout << x / v / cos(p);
	}
}