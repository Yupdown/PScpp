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
		long long n, x;
		cin >> n >> x;

		long long cmb = 0;
		long long pv = sqrt(n) + 1;
		for (long long a = 1; a <= pv; ++a)
		{
			for (long long b = a; b <= pv; ++b)
			{
				long long c = 0;
				for (long long dx = 1048576; dx > 0; dx >>= 1)
				{
					long long cc = c + dx;
					if (a * b + a * cc + b * cc <= n && a + b + cc <= x)
						c = cc;
				}
				cmb += a == b ? c : c * 2;
				if (c > pv)
					cmb += max(a == b ? (c - pv) * 2 : (c - pv) * 4, 0ll);
			}
		}
		cout << cmb << '\n';
	}
}