#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
struct { double r, x, y, z; } holes[10000];

double get_partial_volume(double r, double zmin, double zmax)
{
	zmin = min(max(zmin, -r), r);
	zmax = min(max(zmax, -r), r);

	double vt = M_PI * zmax * (r * r - zmax * zmax / 3);
	double vf = M_PI * zmin * (r * r - zmin * zmin / 3);

	return vt - vf;
}

int main()
{
	FASTIO();
	PRECISION(9);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> holes[i].r >> holes[i].x >> holes[i].y >> holes[i].z;

	double v = 1e+15;
	for (int i = 0; i < n; ++i)
		v -= M_PI * pow(holes[i].r, 3) * 4 / 3;

	double sv = 0;
	for (int i = 0; i < s - 1; ++i)
	{
		double tv = v / s;
		double vf = sv;
		double vt = 100;

		while (vt - vf > 1e-10)
		{
			double vm = (vf + vt) / 2;
			double vp = (vm - sv) * 1e+13;
			for (int j = 0; j < n; ++j)
				vp -= get_partial_volume(holes[j].r, sv * 1000 - holes[j].z, vm * 1000 - holes[j].z);

			if (vp < tv)
				vf = vm;
			else
				vt = vm;
		}

		cout << vf - sv << '\n';
		sv = vf;
	}

	cout << 100 - sv << '\n';
}