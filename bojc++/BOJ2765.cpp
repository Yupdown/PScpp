#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(2);

	int c = 1;
	double d, r, t;
	while (cin >> d >> r >> t && r != 0)
	{
		double dist = (d / (5280 * 12)) * M_PI * r;
		double sped = dist / (t / 3600);
		cout << "Trip #" << c++ << ": " << dist << ' ' << sped << '\n';
	}
}