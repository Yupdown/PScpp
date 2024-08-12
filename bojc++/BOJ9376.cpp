#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char table[102][103];
int memo[3][102][102];

int solution(int n, int m)
{
	memset(memo, 0, sizeof(memo));
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	for (int i = 0; i < n * m; ++i)
	{
		if (table[i / m][i % m] == '$')
		{
			memo [q.size()][i / m][i % m] = 1;
			q.emplace(static_cast<int>(q.size()), i / m, i % m);
		}
	}

	int c = 0;
	while (!q.empty())
	{
		c++;
		vector<tuple<int, int, int>> qp;
		while (!q.empty())
		{
			auto [k, i, j] = q.front();
			q.pop();

			for (int d = 0; d < 4; ++d)
			{
				int ip = i + "1102"[d] - '1';
				int jp = j + "0211"[d] - '1';

				if (ip < 0 || ip >= n || jp < 0 || jp >= m)
					continue;
				if (table[ip][jp] == '*')
					continue;
				if (memo[k][ip][jp] > 0)
					continue;
				memo[k][ip][jp] = c;
				if (table[ip][jp] == '#')
					qp.emplace_back(k, ip, jp);
				else
					q.emplace(k, ip, jp);
			}
		}

		for (const auto& p : qp)
			q.emplace(p);
	}

	int cmin = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (memo[0][i][j] == 0)
				continue;
			int sum = memo[0][i][j] + memo[1][i][j] + memo[2][i][j];
			cmin = min(cmin, sum - (table[i][j] == '#' ? 2 : 3));
		}
	}
	return cmin;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		memset(table, '.', sizeof(table));
		for (int i = 0; i < n; ++i)
			cin >> (table[i + 1] + 1);

		cout << solution(n + 2, m + 2) << '\n';
	}
}