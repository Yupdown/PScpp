#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(8);

	int t;
	cin >> t;
	while (t--)
	{
		long long xa, ya, xc, yc, v;
		cin >> xa >> ya >> xc >> yc >> v;
		if (v == 1)
		{
			cout << "-1\n";
			continue;
		}
		long long dx = xc - xa;
		long long dy = yc - ya;
		double l = sqrt(dx * dx + dy * dy);
		double o = v * v * l / (v * v - 1);
		double r = v * l / (v * v - 1);
		double t = sqrt(o * o - r * r) / v;
		double th = acos((o * o + r * r - v * v * t * t) / (2 * o * r));
		double ph = acos((l * l + t * t - v * v * t * t) / (2 * l * t));
		double k = 1 / sqrt(v * v - 1);
		double sa = (r * r * th - (o - l) * t * sin(ph)) / 2;
		double sb = t * t * (pow(M_E, k * (M_PI - ph) * 2) - 1) / (k * 4);
		cout << (sa + sb) * 2 << "\n";
	}
}