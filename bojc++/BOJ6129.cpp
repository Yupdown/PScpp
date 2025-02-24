#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[100][101];
int memo[100][100][4];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	pair<int, int> s, e;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (table[i][j] == 'A')
				s = { i, j };
			if (table[i][j] == 'B')
				e = { i, j };
		}
	}

	memset(memo, 1, sizeof(memo));
	deque<tuple<int, int, int>> q;
	q.emplace_back(s.first, s.second, 0);
	q.emplace_back(s.first, s.second, 1);
	q.emplace_back(s.first, s.second, 2);
	q.emplace_back(s.first, s.second, 3);
	memo[s.first][s.second][0] = 0;
	memo[s.first][s.second][1] = 0;
	memo[s.first][s.second][2] = 0;
	memo[s.first][s.second][3] = 0;

	while (!q.empty())
	{
		auto [i, j, c] = q.front();
		q.pop_front();

		for (int d = 0; d < 4; ++d)
		{
			int ip = i + "1120"[d] - '1';
			int jp = j + "2011"[d] - '1';
			int v = memo[i][j][c] + (d != c);

			if (ip < 0 || ip >= n || jp < 0 || jp >= n)
				continue;
			if (v >= memo[ip][jp][d])
				continue;
			if (table[ip][jp] == 'x')
				continue;
			memo[ip][jp][d] = v;
			if (d != c)
				q.emplace_back(ip, jp, d);
			else
				q.emplace_front(ip, jp, d);
		}
	}

	cout << *min_element(memo[e.first][e.second], memo[e.first][e.second] + 4);
}