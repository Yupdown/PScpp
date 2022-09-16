#include <bits/stdc++.h>

using namespace std;

pair<double, double> ternary_search(double min, double max, double epsilon, double (*callback)(double))
{
	double lo = min, hi = max;

	while (hi - lo > epsilon)
	{
		double p = (lo * 2.0 + hi) / 3.0;
		double q = (lo + hi * 2.0) / 3.0;

		double dp = callback(p);
		double dq = callback(q);

		if (dp < dq)
			hi = q;
		else
			lo = p;
	}

	double x = lo + hi / 2.0;
	return make_pair(x, callback(x));
}