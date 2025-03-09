#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int NMAX = 100;
constexpr int MMAX = 100;

int table[NMAX][MMAX];
int memo[NMAX][MMAX][4];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n * m; ++i)
		cin >> table[i / m][i % m];

	int ai, aj, ad, bi, bj, bd;
	cin >> ai >> aj >> ad >> bi >> bj >> bd;

	queue<tuple<int, int, int>> q;
	q.emplace(ai - 1, aj - 1, ad - 1); // custom initial position
	memo[ai - 1][aj - 1][ad - 1] = 1;

	while (!q.empty())
	{
		auto [i, j, d] = q.front();
		q.pop();

		for (int x = 1; x <= 3; ++x)
		{
			int ip = i + ("1120"[d] - '1') * x;
			int jp = j + ("2011"[d] - '1') * x;

			if (ip < 0 || ip >= n || jp < 0 || jp >= m)
				break;
			if (table[ip][jp] > 0) // custom condition
				break;
			if (memo[ip][jp][d] > 0)
				continue;

			memo[ip][jp][d] = memo[i][j][d] + 1;
			q.emplace(ip, jp, d);
		}

		for (int x = 0; x < 2; ++x)
		{
			int dp = "32012310"[d + x * 4] - '0';
			if (memo[i][j][dp] > 0)
				continue;

			memo[i][j][dp] = memo[i][j][d] + 1;
			q.emplace(i, j, dp);
		}
	}

	cout << memo[bi - 1][bj - 1][bd - 1] - 1;
}