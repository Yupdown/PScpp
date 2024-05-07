#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[102][102];

bool process(int n, int m, int x, int y)
{
	static decltype(table) flood;
	memset(flood, 0, sizeof(flood));

	int cnt = 0;
	queue<int> q;
	q.push(0);

	while (!q.empty())
	{
		int x = q.front() / m;
		int y = q.front() % m;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xp = x + "0211"[i] - '1';
			int yp = y + "1102"[i] - '1';

			if (xp < 0 || xp >= n)
				continue;
			if (yp < 0 || yp >= m)
				continue;
			if (flood[xp][yp] || table[xp][yp])
				continue;

			q.push(xp * m + yp);
			flood[xp][yp] = 1;
			++cnt;
		}
	}

	if (cnt >= n * m)
		return false;

	for (int i = 0; i < n * m; ++i)
	{
		int x = i / m;
		int y = i % m;

		if (table[x][y] == 0)
			continue;
		int c = 0;
		for (int j = 0; j < 4; ++j)
		{
			int xp = x + "0211"[j] - '1';
			int yp = y + "1102"[j] - '1';

			if (xp < 0 || xp >= n)
				continue;
			if (yp < 0 || yp >= m)
				continue;
			if (flood[xp][yp])
				++c;
		}
		if (c > 1)
			table[x][y] = 0;
	}

	return true;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n * m; ++i)
		cin >> table[i / m + 1][i % m + 1];

	int cnt = 0;
	while (process(n + 2, m + 2, 0, 0))
		++cnt;

	cout << cnt;
}