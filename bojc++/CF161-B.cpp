#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long table[1 << 19];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		memset(table, 0, sizeof(table));
		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			table[v] += 1;
		}

		long long ret = 0;
		int sum = 0;
		for (int i = n; i >= 0; --i)
		{
			sum += table[i];
			long long m = n - sum;

			if (table[i] <= 1)
				continue;

			if (table[i] > 2)
				ret += table[i] * (table[i] - 1) * (table[i] - 2) / 6;
			ret += table[i] * (table[i] - 1) * m / 2;
		}

		cout << ret << '\n';
	}
}