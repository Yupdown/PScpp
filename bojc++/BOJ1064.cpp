#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

inline double distance(int x0, int y0, int x1, int y1)
{
	int dx = x0 - x1;
	int dy = y0 - y1;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	FASTIO();
	PRECISION(12);

	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	double ea = distance(xa, ya, xb, yb);
	double eb = distance(xb, yb, xc, yc);
	double ec = distance(xa, ya, xc, yc);

	double vmin = ea + eb;
	double vmax = ea + eb;
	vmin = min(vmin, ea + ec);
	vmax = max(vmax, ea + ec);

	vmin = min(vmin, eb + ec);
	vmax = max(vmax, eb + ec);

	int o = (yb - ya) * (xc - xb) - (xb - xa) * (yc - yb);
	cout << (o ? (vmax - vmin) * 2.0 : -1);
}