#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, k;
		cin >> n >> k;

		int m = 1;
		int r = 0;
		while (k > 0)
		{
			int s = (n / m + 1) / 2;
			if (s >= k)
				r = m * (k * 2 - 1);
			k -= s;
			m <<= 1;
		}

		cout << r << '\n';
	}
}