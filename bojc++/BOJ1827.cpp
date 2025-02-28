#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

double v, xi[8], yi[8], vi[8], ai[8];

double get_time(double px, double py, double pv, double tx, double ty, double tv, double th)
{
	double dx = px - tx;
	double dy = py - ty;
	double l = sqrt(dx * dx + dy * dy);
	double cost = cos(th - atan2(dy, dx));

	double a = pv * pv - tv * tv;
	double b = tv * l * cost;
	double c = -l * l;

	return (sqrt(b * b - a * c) - b) / a;
}

double permutation(int n, double px, double py, int mask, double t, double astmax)
{
	if (mask == (1 << n) - 1)
		return astmax;

	double res = 1.0e+6;
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1 << i))
			continue;

		double tx = xi[i] + cos(ai[i]) * vi[i] * t;
		double ty = yi[i] + sin(ai[i]) * vi[i] * t;

		double ti = t + get_time(px, py, v, tx, ty, vi[i], ai[i]);

		double npx = xi[i] + cos(ai[i]) * vi[i] * ti;
		double npy = yi[i] + sin(ai[i]) * vi[i] * ti;

		double ast = ti + sqrt(npx * npx + npy * npy) / vi[i];

		res = min(res, permutation(n, npx, npy, mask | (1 << i), ti, max(ast, astmax)));
	}

	return res;
}

int main()
{
	FASTIO();

	int n;

	cin >> n >> v;
	for (int i = 0; i < n; ++i)
		cin >> xi[i] >> yi[i] >> vi[i] >> ai[i];

	cout << round(permutation(n, 0.0, 0.0, 0, 0.0, 0.0)) << endl;
	return 0;
}