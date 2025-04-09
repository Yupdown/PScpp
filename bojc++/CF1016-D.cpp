#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

void d2xy(int n)
{
	long long d;
	cin >> d;
	d--;
	long long x = 1, y = 1;
	for (long long i = 0; i < 30; ++i)
	{
		long long dp = (d >> i * 2) % 4;
		switch (dp)
		{
		case 1:
			x += 1ll << i;
			y += 1ll << i;
			break;
		case 2:
			x += 1ll << i;
			break;
		case 3:
			y += 1ll << i;
			break;
		}
	}

	cout << x << " " << y << "\n";
}

void xy2d(int n)
{
	long long x, y;
	cin >> x >> y;
	x--, y--;
	long long d = 1;
	for (long long i = 0; i < 30; ++i)
	{
		long long xp = (x >> i) % 2;
		long long yp = (y >> i) % 2;
		switch ((xp << 1) + yp)
		{
		case 1:
			d += 3ll << i * 2;
			break;
		case 2:
			d += 2ll << i * 2;
			break;
		case 3:
			d += 1ll << i * 2;
			break;
		}
	}

	cout << d << "\n";
}

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < q; ++i)
		{
			string o;
			cin >> o;
			switch (o[0])
			{
			case '-':
				xy2d(n);
				break;
			case '<':
				d2xy(n);
				break;
			}
		}
	}
}