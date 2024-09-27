#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];

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
			cin >> table[i];
		sort(table, table + n, std::greater<long long>());
		int ret = 1;
		long long acc = accumulate(table, table + n, 0LL);
		for (int i = 0; i < n; ++i)
		{
			k -= table[0] - table[i];
			acc += table[0] - table[i];
			if (k < 0)
				break;
			int d = i + 1;
			long long tacc = (acc + d - 1) / d * d;
			if (tacc - acc <= k)
				ret = max(ret, d);
		}
		cout << ret << '\n';
	}
}