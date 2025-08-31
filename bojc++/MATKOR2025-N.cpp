#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, xs, ys, xf, yf, k;
		cin >> n >> m >> xs >> ys >> xf >> yf >> k;

		// assuming m == 1
		if (abs(xf - xs) != k - 1)
			cout << -1;
		else if (xf < xs)
			cout << string(k - 1, 'L');
		else
			cout << string(k - 1, 'R');
		cout << "\n";
	}
}