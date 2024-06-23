#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100][100];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> table[i][j];

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int s = 0;
				if (i > 0)
					s = max(s, table[i - 1][j]);
				if (j > 0)
					s = max(s, table[i][j - 1]);
				if (i < n - 1)
					s = max(s, table[i + 1][j]);
				if (j < m - 1)
					s = max(s, table[i][j + 1]);
				if (table[i][j] > s)
					table[i][j] = s;
				cout << table[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}