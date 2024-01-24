#include <array>
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
array<double, 3> coef[10];

int main()
{
	FASTIO();
	PRECISION(10);

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; ++i)
		cin >> coef[i][0] >> coef[i][1] >> coef[i][2];

	double sum = 0.0;
	for (int i = 0; i < n; ++i)
		sum += coef[i][2];

	sort(coef, coef + n, [](const array<double, 3>& lhs, const array<double, 3>& rhs) { return lhs[1] > rhs[1]; });

	double ts = 0.0;
	double ys = 0.0;
	for (int i = 0; i < n; ++i)
	{
		ys -= 1.0 / (2.0 * coef[i][0]);
		double yp = -1.0 / ys;
		double ti = t - ts;
		if (i < n - 1)
			ti = min((coef[i + 1][1] - coef[i][1]) / yp, ti);
		sum += yp / 2.0 * ti * ti + coef[i][1] * ti;
		ts += ti;
	}

	cout << sum / n;
}

double in[15][3];
int main2() {
	int N, T, i, j;
	scanf("%d %d", &N, &T);
	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++)
			scanf("%lf", &in[i][j]);

	double st = 0, en = 1e9, mi;
	for (int q = 1; q <= 200; q++) {
		mi = (st + en) / 2;
		double s = 0;
		for (int i = 0; i < N; i++) {
			if (mi >= in[i][1])
				continue;
			if (mi <= in[i][1] + 2 * T * in[i][0]) {
				s += T;
				continue;
			}
			s += (mi - in[i][1]) / (2 * in[i][0]);
		}
		if (s >= T)
			st = mi;
		else
			en = mi;
	}

	double ans = 0;
	for (i = 0; i < N; i++) {
		double v = 0;
		if (mi >= in[i][1])
			v = 0;
		else if (mi <= in[i][1] + 2 * T * in[i][0])
			v = T;
		else
			v = (mi - in[i][1]) / (2 * in[i][0]);

		ans += (in[i][0] * v * v + in[i][1] * v + in[i][2]);
	}
	return !printf("%.20lf\n", ans / N);
}