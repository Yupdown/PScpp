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
	for (int c = 0; c < t; ++c)
	{
		int r, v;
		cin >> r >> v;
		cout << "Case " << c + 1 << ": " << M_PI_2 * r / v << '\n';
	}
}