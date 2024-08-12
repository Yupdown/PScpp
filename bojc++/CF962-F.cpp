#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long a[200000];
long long b[200000];

long long pred(int n, long long x)
{
	long long k = 0;
	for (int i = 0; i < n; ++i)
		k += max(0ll, (a[i] + b[i] - x - 1) / b[i]);
	return k;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		long long n, k;
		cin >> n >> k;

		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];

		long long x = (1 << 30) - 1;
		for (long long dx = 1 << 29; dx > 0; dx >>= 1)
		{
			if (pred(n, x - dx) <= k)
				x -= dx;
		}
		long long s = 0;
		long long r = k - pred(n, x);
		for (int i = 0; i < n; ++i)
		{
			long long ki = max(0ll, (a[i] + b[i] - x - 1) / b[i]);
			s += ki * a[i] - b[i] * (ki * (ki + 1) / 2 - ki);
			a[i] = max(0ll, a[i] - b[i] * ki);
		}
		sort(a, a + n, greater<long long>());
		s += accumulate(a, a + min(n, r), 0ll);

		cout << s << '\n';
	}
}