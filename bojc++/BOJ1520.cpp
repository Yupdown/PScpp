#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[500][500];
int memo[500][500];

int solution(int n, int m, int i, int j)
{
	if (memo[i][j] >= 0)
		return memo[i][j];

	memo[i][j] = 0;
	for (int d = 0; d < 4; ++d)
	{
		int ip = i + "0211"[d] - '1';
		int jp = j + "1102"[d] - '1';

		if (ip < 0 || ip >= n || jp < 0 || jp >= m)
			continue;
		if (table[ip][jp] >= table[i][j])
			continue;
		memo[i][j] += solution(n, m, ip, jp);
	}

	return memo[i][j];
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> table[i][j];
	}

	memset(memo, -1, sizeof(memo));
	memo[n - 1][m - 1] = 1;
	cout << solution(n, m, 0, 0);
}