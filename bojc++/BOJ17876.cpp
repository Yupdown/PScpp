#include <bits/stdc++.h>

using namespace std;
char table[6][7];
int matrix[6][4] = {
	4, 2, 3, 1,
	5, 4, 0, 3,
	5, 3, 0, 4,
	5, 1, 0, 2,
	5, 2, 0, 1,
	3, 2, 4, 1
};
int mark[6];

int main()
{
	for (int i = 0; i < 6; ++i)
		cin >> table[i];
	mark[0] = 1;

	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < 36; ++i)
	{
		int x = i / 6;
		int y = i % 6;
		if (table[x][y] == '#')
		{
			q.push(make_tuple(x, y, 0, 4));
			break;
		}
	}

	while (!q.empty())
	{
		auto [x, y, f, u] = q.front();
		q.pop();
		table[x][y] = '.';
		int offset = find(matrix[f], matrix[f] + 4, u) - matrix[f];
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + "0121"[i] - '1';
			int ny = y + "1210"[i] - '1';

			if (nx < 0 || nx >= 6 || ny < 0 || ny >= 6)
				continue;
			if (table[nx][ny] != '#')
				continue;

			int nf = matrix[f][(offset + i) % 4];
			int noffset = find(matrix[nf], matrix[nf] + 4, f) - matrix[nf];
			int nu = matrix[nf][(noffset + 6 - i) % 4];

			if (mark[nf])
			{
				cout << "cannot fold";
				return 0;
			}

			mark[nf] = 1;
			q.push(make_tuple(nx, ny, nf, nu));
		}
	}

	cout << "can fold";
}