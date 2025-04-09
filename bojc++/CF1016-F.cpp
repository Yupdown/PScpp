#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

string s[500];
int table[500];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		memset(table, 0, sizeof(table));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		int vmax = 0;
		for (int i = 0; i < m; ++i)
		{
			int v = 0;
			for (int j = 0; j < n; ++j)
			{
				string st;
				cin >> st;
				if (s[j] == st)
				{
					v++;
					table[j] |= 1;
				}
			}
			vmax = max(vmax, v);
		}
		if (accumulate(table, table + n, 0) < n)
			cout << -1 << "\n";
		else
			cout << n * 3 - vmax * 2 << "\n";
	}
}