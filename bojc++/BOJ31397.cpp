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

double triangle_size(double ax, double ay, double bx, double by, double cx, double cy)
{
	return abs((by - ay) * (cx - bx) - (bx - ax) * (cy - by));
}

double size_segment(int n, int i, double ti, int j, double tj)
{
	int i0 = i;
	int j0 = j;
	if (i > j)
	{
		swap(i0, j0);
		swap(ti, tj);
	}
	int i1 = (i0 + 1) % n;
	int j1 = (j0 + 1) % n;
	double s = spsum[j0] - spsum[i1];
	double ix = lerp(xi[i0], xi[i1], ti);
	double iy = lerp(yi[i0], yi[i1], ti);
	double jx = lerp(xi[j0], xi[j1], tj);
	double jy = lerp(yi[j0], yi[j1], tj);
	s += triangle_size(xi[0], yi[0], ix, iy, xi[i1], yi[i1]);
	s += triangle_size(xi[0], yi[0], xi[j0], yi[j0], jx, jy);
	s -= triangle_size(xi[0], yi[0], ix, iy, jx, jy);
	return i > j ? s : spsum[n] - s;
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
		spsum[i + 1] = spsum[i] + triangle_size(xi[0], yi[0], xi[i], yi[i], xi[(i + 1) % n], yi[(i + 1) % n]);
	}

	double dl = 0;
	double dr = dpsum[n] * 0.5;
	auto [i, ti, j, tj] = get_ij(n, dl, dr);
	double cz = size_segment(n, i, ti, j, tj) - spsum[n] * 0.5;
	for (int k = 0; k < 100; ++k)
	{
		double dm = (dl + dr) * 0.5;
		double di = dm;
		double dj = dm + dpsum[n] * 0.5;
		if (dj >= dpsum[n])
			dj -= dpsum[n];
		tie(i, ti, j, tj) = get_ij(n, di, dj);
		double cs = size_segment(n, i, ti, j, tj) - spsum[n] * 0.5;
		if (cs * cz > 0.0)
			dl = dm;
		else
			dr = dm;
	}

	cout << "YES\n";
	cout << i + 1 << " " << ti << "\n";
	cout << j + 1 << " " << tj << "\n";
}