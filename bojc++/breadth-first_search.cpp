#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int NMAX = 1;
constexpr int MMAX = 1;

int table[NMAX][MMAX];
int memo[NMAX][MMAX];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n * m; ++i)
		cin >> table[i / m][i % m];

	queue<pair<int, int>> q;
	q.emplace(0, 0); // custom initial position
	memo[0][0] = 1;

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
			if (table[ip][jp] > 0) // custom condition
				continue;

			memo[ip][jp] = memo[i][j] + 1;
			q.emplace(ip, jp);
		}
	}
}