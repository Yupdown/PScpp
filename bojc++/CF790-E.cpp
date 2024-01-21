#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int candies[150000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, q;
		cin >> n >> q;

		for (int i = 0; i < n; ++i)
			cin >> candies[i];

		sort(candies, candies + n, greater<int>());

		for (int i = 1; i < n; ++i)
			candies[i] += candies[i - 1];

		for (int i = 0; i < q; ++i)
		{
			int xj;
			cin >> xj;

			int x = n;
			if (xj > candies[n - 1])
				x = -1;
			else
			{
				for (int dx = 1 << 17; dx > 0; dx >>= 1)
				{
					if (x - dx < 0)
						continue;
					if (candies[x - dx] >= xj)
						x -= dx;
				}
				x += 1;
			}

			cout << x << '\n';
		}
	}
}