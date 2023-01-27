#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

const double PI = 3.14159265358979;
const double DEG2RAD = PI / 180.0;

int main()
{
	FASTIO();

	double d, h;
	cin >> d >> h;

	while (true)
	{
		double a, b, c;
		cin >> a >> b >> c;

		if (!(a > 0.0 && b > 0.0 && c > 0.0))
			break;

		double ka = tan(a * DEG2RAD);
		double kb = tan(b * DEG2RAD);
		double kc = tan(c * DEG2RAD);

		ka *= ka;
		kb *= kb;
		kc *= kc;

		double z = sqrt((2.0 * d * d * ka * kb * kc) / (ka * kb + kb * kc - ka * kc * 2.0));
		cout << round(z + h) << "\n";
	}
}