#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100][100][2];

void func(int n, int i, int j, int k)
{
	queue<pair<int, int>> q;
	table[i][j][1] = k;

	q.push(make_pair(i, j));
	while (!q.empty())
	{
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ni = ci + "0211"[d] - '1';
			int nj = cj + "1102"[d] - '1';

			if (ni < 0 || ni >= n)
				continue;
			if (nj < 0 || nj >= n)
				continue;
			if (table[ni][nj][0] == 0 || table[ni][nj][1] != 0)
				continue;

			q.push(make_pair(ni, nj));
			table[ni][nj][1] = k;
		}
	}
}

int main()
{
	FASTIO();

	int n;
	queue<pair<int, int>> q;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> table[i][j][0];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (table[i][j][0] != 0)
			{
				q.push(make_pair(i, j));
				if (table[i][j][1] == 0)
					func(n, i, j, i + j * n + 1);
			}
		}
	}

	int minv = 1 << 10;
	while (!q.empty())
	{
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ni = ci + "0211"[d] - '1';
			int nj = cj + "1102"[d] - '1';

			if (ni < 0 || ni >= n)
				continue;
			if (nj < 0 || nj >= n)
				continue;
			if (table[ni][nj][0] != 0)
			{
				if (table[ni][nj][1] != table[ci][cj][1])
					minv = min(minv, table[ci][cj][0] + table[ni][nj][0] - 2);
				continue;
			}

			q.push(make_pair(ni, nj));
			table[ni][nj][0] = table[ci][cj][0] + 1;
			table[ni][nj][1] = table[ci][cj][1];
		}
	}

	cout << minv;
}