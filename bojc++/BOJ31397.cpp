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

tuple<int, double, int, double> get_ij(int n, double di, double dj)
{
	int i = 0;
	int j = 0;
	for (int dx = 1 << 17; dx > 0; dx >>= 1)
	{
		if (i + dx < n && dpsum[i + dx] < di)
			i += dx;
		if (j + dx < n && dpsum[j + dx] < dj)
			j += dx;
	}
	double ti = (di - dpsum[i]) / (dpsum[i + 1] - dpsum[i]);
	double tj = (dj - dpsum[j]) / (dpsum[j + 1] - dpsum[j]);

	return make_tuple(i, ti, j, tj);
}

double get_size_difference(int n, double di, double dj)
{
	auto [i, ti, j, tj] = get_ij(n, di, dj);
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

	double dl = 0;
	double dr = dpsum[n] * 0.5;
	double cz = get_size_difference(n, dl, dr);
	for (int k = 0; k < 100; ++k)
	{
		double dm = (dl + dr) * 0.5;
		double di = dm;
		double dj = dm + dpsum[n] * 0.5;
		if (dj >= dpsum[n])
			dj -= dpsum[n];
		double cs = get_size_difference(n, di, dj);
		if (cs * cz > 0.0)
			dl = dm;
		else
			dr = dm;
	}

	cout << "YES\n";
	double di = dl;
	double dj = dl + dpsum[n] * 0.5;
	if (dj >= dpsum[n])
		dj -= dpsum[n];
	auto [i, ti, j, tj] = get_ij(n, di, dj);
	cout << i + 1 << " " << ti << "\n";
	cout << j + 1 << " " << tj << "\n";
}