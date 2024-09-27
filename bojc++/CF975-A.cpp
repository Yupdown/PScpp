#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[100];
int memo[100][100];

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
		memset(memo, 0, sizeof(memo));
		memcpy(memo, table, sizeof(table));
		int ret = *max_element(table, table + n) + 1;
		for (int i = 1; i < n; ++i)
		{
			int vmax = 0;
			for (int j = 2; j < n; ++j)
			{
				for (int k = 0; k <= j - 2; ++k)
				{
					if (memo[i - 1][k])
						memo[i][j] = max(memo[i][j], max(memo[i - 1][k], table[j]));
				}
				if (memo[i][j])
					ret = max(ret, memo[i][j] + i + 1);
			}
		}
		cout << ret << '\n';
	}
}