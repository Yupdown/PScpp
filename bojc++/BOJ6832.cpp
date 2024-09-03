#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int NMAX = 32;
constexpr int MMAX = 32;

char table[NMAX][MMAX];
int memo[NMAX][MMAX];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		memset(memo, -1, sizeof(memo));

		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i)
			cin >> table[i];

		queue<pair<int, int>> q;
		q.emplace(0, 0); // custom initial position
		memo[0][0] = 1;

		while (!q.empty())
		{
			auto [i, j] = q.front();
			q.pop();

			for (int d = 0; d < 4; ++d)
			{
				if (table[i][j] == '|' && ~d & 2)
					continue;
				if (table[i][j] == '-' && d & 2)
					continue;

				int ip = i + "1120"[d] - '1';
				int jp = j + "2011"[d] - '1';

				if (ip < 0 || ip >= n || jp < 0 || jp >= m)
					continue;
				if (memo[ip][jp] > 0)
					continue;
				if (table[ip][jp] == '*') // custom condition
					continue;

				memo[ip][jp] = memo[i][j] + 1;
				q.emplace(ip, jp);
			}
		}

		cout << memo[n - 1][m - 1] << '\n';
	}
}