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
		int xa, ya, xc, yc, v;
		cin >> xa >> ya >> xc >> yc >> v;
		if (xa == xc && ya == yc)
			cout << "0\n";
		else
			cout << "-1\n";
	}
}