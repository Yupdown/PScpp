#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
string table[200];
int memo[200][200];

int main()
{
	FASTIO();

	int n, m;
	while (cin >> n >> m && n > 0 && m > 0)
	{
		memset(memo, 0, sizeof(memo));

		for (int i = 0; i < n; ++i)
			cin >> table[i];
		for (int i = 0; i < n; ++i)
		{
			for (int j = m - 1; j > 0; --j)
			{
				bool corner = (i == 0 || i == n - 1) && j == m - 1;
				table[i][j] = corner || table[i][j - 1] != 'S' ? table[i][j] : 'S';
			}
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < m; ++i)
		{
			if (table[0][i] == 'S')
			{
				q.emplace(0, i);
				memo[0][i] = 1;
			}
		}

		int vmin = INT_MAX;
		while (!q.empty())
		{
			auto [i, j] = q.front();
			q.pop();

			if (i == n - 1)
				vmin = min(vmin, memo[i][j]);

			for (int d = 0; d < 4; ++d)
			{
				int ip = i + "1102"[d] - '1';
				int jp = j + "0211"[d] - '1';

				if (ip < 0 || ip >= n || jp < 0 || jp >= m)
					continue;
				if (table[ip][jp] != 'S')
					continue;
				if (memo[ip][jp] > 0)
					continue;

				memo[ip][jp] = memo[i][j] + 1;
				q.emplace(ip, jp);
			}
		}

		cout << vmin << '\n';
	}
}