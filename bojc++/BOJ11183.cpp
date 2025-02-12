#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char table[1024][1024];
int memo[1024][1024];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i > 0 && i < n - 1 && j > 0 && j < m - 1)
				continue;
			if (table[i][j] == '1')
				continue;
			q.emplace(i, j);
			memo[i][j] = 1;
		}
	}

	while (!q.empty())
	{
		auto [i, j] = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ip = i + "1120"[d] - '1';
			int jp = j + "2011"[d] - '1';

			if (ip < 0 || ip >= n || jp < 0 || jp >= m)
				continue;
			if (memo[ip][jp] > 0)
				continue;
			if (table[ip][jp] == '1')
				continue;

			memo[ip][jp] = memo[i][j] + 1;
			q.emplace(ip, jp);
		}
	}
	
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (memo[i][j])
				continue;
			ret += i == 0 || memo[i - 1][j];
			ret += i == n - 1 || memo[i + 1][j];
			ret += j == 0 || memo[i][j - 1];
			ret += j == m - 1 || memo[i][j + 1];
		}
	}

	cout << ret;
}