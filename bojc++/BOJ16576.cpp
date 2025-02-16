#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char table[500][501];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	if (n <= 2 || m <= 2)
	{
		int r0 = 0;
		for (int k = 1; k < max(n, m) - 1; ++k)
		{
			bool ns = n > m;
			if (table[ns ? k : 0][ns ? 0 : k] != '#' && table[ns ? k : 1][ns ? 1 : k] != '#')
				++r0;
		}
		cout << r0;
	}
	else
	{
		int r0 = 0, r1 = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (i > 0 && i < n - 1 && j > 0 && j < m - 1 && table[i][j] == '.')
					++r0;
				if ((i == 0 || i == n - 1) != (j == 0 || j == m - 1) && table[i][j] == '#')
					++r1;
			}
		}
		cout << r0 + !r1;
	}
}