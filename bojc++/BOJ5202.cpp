#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(2);

	int k;
	cin >> k;
	
	for (int i = 0; i < k; ++i)
	{
		double w, h, r, d, a1, a2;
		cin >> w >> h >> r >> d >> a1 >> a2;

		double lhs = d / tan(a2 * M_PI / 180);
		double rhs = d / tan(a1 * M_PI / 180);
		double dx = w / 2 < r ? sqrt(r * r - w * w / 4) : 0;
		double x1 = rhs - d;
		double x2 = rhs - dx;
		double x3 = lhs + dx; 
		double x4 = lhs + d;
		double ret = 0;
		cout << "Data Set " << i + 1 << ":\n" << ret << "%\n";
	}
}