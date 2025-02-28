#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;
typedef long double ld;

ld function_height(ld n, ld m, ld f, ld d)
{
	return (m - f * f * d * d) / (n - d);
}

int main()
{
	FASTIO();

	cout << fixed;
	cout.precision(8);

	ld n, m;
	ld f;
	cin >> n >> m >> f;

	ld lo = 0, hi = n - 1;
	ld p, q, dp, dq;

	while (hi - lo > 1.e-8)
	{
		p = (lo * 2.0 + hi) / 3.0;
		q = (lo + hi * 2.0) / 3.0;

		dp = function_height(n, m, f, p);
		dq = function_height(n, m, f, q);

		if (dp >= dq)
			hi = q;
		else
			lo = p;
	}

	double ra = function_height(n, m, f, floor(p));
	double rb = function_height(n, m, f, ceil(p));

	cout << ((n - p) > 1.0 ? max(ra, rb) : ra) << '\n';
	return 0;
}