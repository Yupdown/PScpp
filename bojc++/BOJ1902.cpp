#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

double function_height(pair<double, double>* mb, int n, double x)
{
	double y = 0.0;
	for (int i = 0; i < n - 1; ++i)
		y = max(y, mb[i].first * x + mb[i].second);
	return y;
}

int main()
{
	FASTIO();

	cout << fixed;
	cout.precision(2);

	int n;
	cin >> n;

	pair<double, double> mb[5000];
	pair<int, int> minmax;
	for (int i = 0, lx, ly; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		if (i > 0)
		{
			if (i == n - 1)
				minmax.second = x;

			mb[i - 1].first = (double)(y - ly) / (x - lx);
			mb[i - 1].second = ly - mb[i - 1].first * lx;
		}
		else
			minmax.first = x;

		lx = x;
		ly = y;
	}

	double lo = minmax.first, hi = minmax.second;
	double p, q, dp, dq;

	while (hi - lo > 1.e-6)
	{
		p = (lo * 2.0 + hi) / 3.0;
		q = (lo + hi * 2.0) / 3.0;

		dp = function_height(mb, n, p);
		dq = function_height(mb, n, q);

		if (dp < dq)
			hi = q;
		else
			lo = p;
	}

	cout << dp << '\n';
	return 0;
}