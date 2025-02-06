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
		int n, k = 2;
		cin >> n;
		while (n--)
		{
			int v[2];
			char o[2];
			cin >> o[0] >> v[0] >> o[1] >> v[1];
			int kt = 0;
			for (int h = 0; h < 2; ++h)
			{
				for (int i = 0; i < 7; ++i)
				{
					if (k >> i & 1)
						kt |= 1 << (o[h] == '+' ? i + v[h] : i * v[h]) % 7;
				}
			}
			k = kt;
		}
		cout << (k & 1 ? "LUCKY\n" : "UNLUCKY\n");
	}
}