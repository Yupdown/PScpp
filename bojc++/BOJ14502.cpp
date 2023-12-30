#include <bits/stdc++.h>

using namespace std;

int input[8][8];
int table_temp[8][8];

int simulation(int n, int m)
{
	int res = 0;
	queue<pair<int, int>> bfs;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			table_temp[i][j] = input[i][j];
			switch (input[i][j])
			{
			case 0:
				++res;
				break;
			case 2:
				bfs.push(make_pair(i, j));
				break;
			}
		}
	}

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
				
				int* ptr = &table_temp[next_nodes[j][0]][next_nodes[j][1]];
				if (*ptr > 0)
					continue;

				*ptr = 1;
				--res;
				bfs.push(make_pair(next_nodes[j][0], next_nodes[j][1]));
			}
		}
	}

	return res;
}

int combination(int n, int m, int i, int j)
{
	int res = 0;
	for (int k = j; k < n * m; ++k)
	{
		int* ptr = &input[k / m][k % m];
		if (*ptr > 0)
			continue;

		*ptr = 1;
		if (i < 2)
			res = max(res, combination(n, m, i + 1, k + 1));
		else
			res = max(res, simulation(n, m));
		*ptr = 0;
	}

	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> input[i][j];
	}

	cout << combination(n, m, 0, 0);
}