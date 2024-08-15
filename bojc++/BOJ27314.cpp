#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<string> table;
vector<vector<vector<int>>> memo;

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	table.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	
	queue<tuple<int, int, int>> q;
	int gp = 0;
	for (int i = 0; i < n * m; ++i)
	{
		if (table[i / m][i % m] == '#')
			q.emplace(gp++, i / m, i % m);
	}

	memo.resize(q.size());
	for (auto& m1 : memo)
	{
		m1.resize(n);
		for (auto& m2 : m1)
			m2.resize(m);
	}

	vector<int> pv(memo.size());
	while (!q.empty())
	{
		auto [p, i, j] = q.front();
		q.pop();

		if (pv[p] && memo[p][i][j] > pv[p])
			continue;

		for (int d = 0; d < 4; ++d)
		{
			int ip = i + "1120"[d] - '1';
			int jp = j + "2011"[d] - '1';

			if (ip < 0 || ip >= n || jp < 0 || jp >= m)
				continue;
			if (memo[p][ip][jp] > 0)
				continue;
			if (table[ip][jp] == 'X') // custom condition
				continue;

			memo[p][ip][jp] = memo[p][i][j] + 1;
			q.emplace(p, ip, jp);

			if (table[ip][jp] == 'H')
				pv[p] = memo[p][ip][jp];
		}
	}

	int ret = 0;
	for (int p = 0; p < pv.size(); ++p)
	{
		if (pv[p] == 0)
			continue;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (memo[p][i][j] && memo[p][i][j] <= pv[p] && table[i][j] == 'P')
					++cnt;
			}
		}
		ret = max(ret, cnt);
	}

	cout << ret;
}