#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1 << 21];
int memo[1 << 21];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(table, 0, sizeof(int) * n);
		memset(memo, 0, sizeof(int) * (n + 2));
		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			table[v - 1]++;
		}
		for (int i = 0; i < n; ++i)
		{
			int a = table[i];
			for (int s = 1; s < a; ++s)
			{
				int m = (a + s - 1) / s;
				int mp = m * s - a;
				if (mp <= m)
					memo[s]++;
			}
			memo[a]++;
			memo[a + 1]++;
		}
		int target = count_if(table, table + n, [](int x) { return x; });
		int s = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (memo[i] >= target)
				s = i;
		}
		int m = 0;
		for (int i = 0; i < n; ++i)
			m += (table[i] + s - 1) / s;
		cout << m << "\n";
	}
}