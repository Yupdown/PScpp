#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int table[100000];

int main()
{
	FASTIO();
	PRECISION(6);

	double n, h, s;
	cin >> n >> h >> s;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	double hpiv = s / n;
	double dmin = min(hpiv, h - hpiv);
	double a = hpiv - dmin;
	double b = hpiv + dmin;

	double reta = 0;
	double retb = 0;
	for (int i = 0; i < n; ++i)
	{
		double tl = static_cast<double>(i) / n;
		double tr = static_cast<double>(i + 1) / n;
		reta += (a * (1 - tl) + b * tl + a * (1 - tr) + b * tr) * table[i] / 2;
		retb += (b * (1 - tl) + a * tl + b * (1 - tr) + a * tr) * table[i] / 2;
	}
	cout << min(reta, retb);
}