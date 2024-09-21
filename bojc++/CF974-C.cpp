#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];

int solution(int n, long long x)
{
	long long s = accumulate(table, table + n, 0LL) + x;
	long long r = 0;
	for (int i = 0; i < n - 1; ++i)
		r += table[i] * n * 2 < s;
	return r;
}

int main()
{
	FASTIO();
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		sort(table, table + n);
		long long x = 0;
		if (solution(n, 0) * 2 > n)
		{
			cout << 0 << '\n';
		}
		else
		{
			for (long long dx = 1LL << 60; dx; dx >>= 1)
			{
				if (solution(n, x + dx) * 2 <= n)
					x += dx;
			}
			cout << (x == 2305843009213693951LL ? -1 : x + 1) << '\n';
		}
	}
}