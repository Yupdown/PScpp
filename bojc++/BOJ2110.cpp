#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int xi[200000];

int functionx(int n, int c, int x)
{
	for (int i = 0; i < n; --c)
	{
		int tx = xi[i] + x;
		while (i < n && xi[i] <= tx)
			++i;
	}
	return c > 0;
}

int main()
{
	FASTIO();

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; ++i)
		cin >> xi[i];

	sort(xi, xi + n);

	int x = 0;
	for (int dx = 1 << 29; dx > 0; dx >>= 1)
	{
		if (!functionx(n, c, x + dx))
			x += dx;
	}

	cout << x + 1;
}