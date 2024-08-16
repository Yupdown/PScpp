#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[1000000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i];
	for (int i = 1; i < n; ++i)
		table[i] += table[i - 1];

	long long ret = 0;
	for (int x = 1; x <= n - 2; ++x)
	{
		long long sig0x = table[x - 1];
		
		int ymin = x;
		int ymax = x;

		for (int dy = 1 << 19; dy; dy >>= 1)
		{
			int y = ymin + dy;
			if (y > n - 1)
				continue;
			long long sigxy = table[y - 1] - sig0x;
			long long sigyn = table[n - 1] - sigxy - sig0x;
			if (sigxy <= sig0x || sigxy <= sigyn)
				ymin = y;
		}

		for (int dy = 1 << 19; dy; dy >>= 1)
		{
			int y = ymax + dy;
			if (y > n - 1)
				continue;
			long long sigxy = table[y - 1] - sig0x;
			long long sigyn = table[n - 1] - sigxy - sig0x;
			if (sigyn > sig0x)
				ymax = y;
		}

		ret += max(0, ymax - ymin);
	}

	cout << ret;
}