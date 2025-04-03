#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
using int64 = long long;

double imos[1 << 17];

int main()
{
	FASTIO();
	PRECISION(12);

	int h, q, r;
	cin >> h >> q >> r;
	for (int i = 0; i < q; ++i)
	{
		int64 a, b;
		cin >> a >> b;
		int64 hp = static_cast<int64>((sqrt(a * 8 - 1) - 1) / 2) + 1;
		int64 s = a - (hp - 1) * hp / 2 - 1;
		int64 e = h - hp * (hp + 1) / 2 + a;
		int64 c = e - s + 1;
		double v = static_cast<double>(b) / c;
		imos[s + 1] += v;
		imos[e + 2] -= v;
	}
	for (int i = 1; i <= h + 1; ++i)
		imos[i + 1] += imos[i];
	for (int i = 0; i < h + 1; ++i)
		imos[i + 1] += imos[i];
	for (int i = 0; i < r; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << imos[b] - imos[a - 1] << "\n";
	}
}