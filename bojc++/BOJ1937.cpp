#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[500][500];
int memo[500][500];

int dfs(int n, int i, int j, int c)
{
	if (memo[i][j] > 0)
		return memo[i][j];

	memo[i][j] = 1;
	for (int d = 0; d < 4; ++d)
	{
		int ip = i + "0211"[d] - '1';
		int jp = j + "1102"[d] - '1';

		if (ip < 0 || ip >= n)
			continue;
		if (jp < 0 || jp >= n)
			continue;
		if (table[ip][jp] > table[i][j])
			memo[i][j] = max(memo[i][j], dfs(n, ip, jp, c + 1) + 1);
	}
	return memo[i][j];
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n * n; ++i)
		cin >> table[i / n][i % n];

	int vmax = 0;
	for (int i = 0; i < n * n; ++i)
		vmax = max(vmax, dfs(n, i / n, i % n, 0));
	cout << vmax;
}