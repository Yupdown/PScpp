#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<long long, long long> solution(long long x, long long y)
{
	for (long long a = 10; a <= 15000; ++a)
	{
		long long n = a * a * (x / 100 % 10) + a * (x / 10 % 10) + (x % 10);
		long long b = 9;
		for (long long db = 8192; db > 0; db >>= 1)
		{
			long long bp = b + db;
			if (bp > 15000)
				continue;
			long long m = bp * bp * (y / 100 % 10) + bp * (y / 10 % 10) + (y % 10);
			if (m == n)
				return { a, bp };
			else if (m < n)
				b = bp;
		}
	}
	return {};
}

int main()
{
	FASTIO();

	int k;
	cin >> k;
	while (k--)
	{
		long long x, y;
		cin >> x >> y;
		auto [a, b] = solution(x, y);
		cout << a << ' ' << b << '\n';
	}
}