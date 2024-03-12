#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	sort(table, table + n);

	int lhs = 0, rhs = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		int f = i + 1;
		int t = n;

		while (f + 1 < t)
		{
			int m = (f + t) / 2;
			if (table[i] + table[m] < 0)
				f = m;
			else
				t = m;
		}

		if (abs(table[i] + table[f]) < abs(table[lhs] + table[rhs]))
		{
			lhs = i;
			rhs = f;
		}
		if (f < n - 1 && abs(table[i] + table[f + 1]) < abs(table[lhs] + table[rhs]))
		{
			lhs = i;
			rhs = f + 1;
		}
	}

	cout << table[lhs] << ' ' << table[rhs];
}