#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
using int64 = long long;

int64 xi[200000];
int64 yi[200000];
double dpsum[200001];
double spsum[200001];

double lerp(double a, double b, double t)
{
	return a + (b - a) * t;
}

double get_size(double ax, double ay, double bx, double by, double cx, double cy)
{
	return abs((by - ay) * (cx - bx) - (bx - ax) * (cy - by));
}

double size_segment(int n, int li, int ri)
{
	double tr = get_size(xi[0], yi[0], xi[li], yi[li], xi[ri], yi[ri]);
	return li <= ri ? spsum[ri] - spsum[li] - tr : spsum[ri] + spsum[n] - spsum[li] + tr;
}

double get_size_difference(int n, int i, int j, double ti, double tj)
{
	int ip = (i + 1) % n;
	int jp = (j + 1) % n;
	double si = size_segment(n, ip, j);
	double sj = size_segment(n, jp, i);
	double dxi = lerp(xi[i], xi[ip], ti);
	double dyi = lerp(yi[i], yi[ip], ti);
	double dxj = lerp(xi[j], xi[jp], tj);
	double dyj = lerp(yi[j], yi[jp], tj);
	si += get_size(dxi, dyi, xi[ip], yi[ip], xi[j], yi[j]) + get_size(dxi, dyi, dxj, dyj, xi[j], yi[j]);
	sj += get_size(dxj, dyj, xi[jp], yi[jp], xi[i], yi[i]) + get_size(dxi, dyi, dxj, dyj, xi[i], yi[i]);
	return si - sj;
}

int main()
{
	FASTIO();
	PRECISION(12);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> xi[i] >> yi[i];
	for (int i = 0; i < n; ++i)
	{
		int64 dx = xi[(i + 1) % n] - xi[i];
		int64 dy = yi[(i + 1) % n] - yi[i];
		dpsum[i + 1] = dpsum[i] + sqrt(dx * dx + dy * dy);
		spsum[i + 1] = spsum[i] + get_size(xi[0], yi[0], xi[i], yi[i], xi[(i + 1) % n], yi[(i + 1) % n]);
	}

	int i = 0;
	int j = 0;
	for (double di = 0, ls; di < dpsum[n]; di += 1)
	{
		if (di >= dpsum[i + 1])
			di = dpsum[++i];
		double dj = di + dpsum[n] * 0.5;
		while (j < n && dj >= dpsum[j + 1])
			++j;
		j %= n;
		if (dj >= dpsum[n])
			dj -= dpsum[n];
		double ti = (di - dpsum[i]) / (dpsum[i + 1] - dpsum[i]);
		double tj = (dj - dpsum[j]) / (dpsum[j + 1] - dpsum[j]);
		double cs = get_size_difference(n, i, j, ti, tj);
		if (di > 0 && cs * ls <= 0)
		{
			int li, lj;
			double tl = 0, tr = -1, lti, ltj;
			for (int k = 0; k < 100; ++k)
			{
				double tm = (tl + tr) * 0.5;
				double ldi = di + tm;
				double ldj = dj + tm;
				li = ldi < dpsum[i] ? (i + n - 1) % n : i;
				lj = ldj < dpsum[j] ? (j + n - 1) % n : j;
				lti = (ldi - dpsum[li]) / (dpsum[li + 1] - dpsum[li]);
				ltj = (ldj - dpsum[lj]) / (dpsum[lj + 1] - dpsum[lj]);

				if (get_size_difference(n, li, lj, lti, ltj) * cs > 0.0)
					tl = tm;
				else
					tr = tm;
			}

			cout << "YES\n";
			cout << li + 1 << " " << lti << "\n";
			cout << lj + 1 << " " << ltj << "\n";
			return 0;
		}
		ls = cs;
	}

	cout << "NO\n";
}