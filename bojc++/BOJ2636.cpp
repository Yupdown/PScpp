#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[100][100];

int simulate(int n, int m, int c)
{
	int res = 0;
	queue<pair<int, int>> exp;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			res += table[i][j] < 0;
			if (i == 0 || i + 1 == n || j == 0 || j + 1 == m)
				exp.push(make_pair(i, j));
		}
	}

	if (!res)
		return 0;

	while (!exp.empty())
	{
		pair<int, int> cur = exp.front();
		exp.pop();

		if (table[cur.first][cur.second] >= c)
			continue;

		queue<pair<int, int>> bfs;
		bfs.push(cur);

		while (!bfs.empty())
		{
			for (int i = bfs.size(); i > 0; --i)
			{
				int x = bfs.front().first;
				int y = bfs.front().second;
				bfs.pop();

				int next_nodes[][2] = { x + 1, y, x - 1, y, x, y + 1, x, y - 1 };
				for (int j = 0; j < 4; ++j)
				{
					if (next_nodes[j][0] < 0 || next_nodes[j][0] >= n)
						continue;
					if (next_nodes[j][1] < 0 || next_nodes[j][1] >= m)
						continue;

					int* ptr = &table[next_nodes[j][0]][next_nodes[j][1]];
					if (*ptr >= c)
						continue;

					if (*ptr >= 0)
						bfs.push(make_pair(next_nodes[j][0], next_nodes[j][1]));
					*ptr = c;
				}
			}
		}
	}

	return res;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int v;
			cin >> v;
			table[i][j] = -v;
		}
	}

	int cnt = 0, c = 0, l = 0;
	do
	{
		l = c;
		c = simulate(n, m, ++cnt);
	} while (c);

	cout << cnt - 1 << '\n' << l;
}