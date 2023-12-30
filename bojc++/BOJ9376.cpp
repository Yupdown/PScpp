#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char input[102][102];
int memo[3][102][102];

void flood_room(int h, int w, int r, int c, int n)
{
	const int adj[][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

	queue<array<int, 2>> bfs[2];
	bfs[0].push(array<int, 2>{ r, c });
	int m = 0;

	while (!bfs[m % 2].empty())
	{
		auto& cbfs = bfs[m % 2];
		auto& nbfs = bfs[(m + 1) % 2];

		while (!cbfs.empty())
		{
			int r = cbfs.front()[0];
			int c = cbfs.front()[1];
			cbfs.pop();

			memo[n][r][c] = m;

			for (int i = 0; i < 4; ++i)
			{
				int rp = r + adj[i][0];
				int cp = c + adj[i][1];

				if (rp < 0 || rp > h + 1 || cp < 0 || cp > w + 1)
					continue;
				if (memo[n][rp][cp] >= 0)
					continue;
				if (input[rp][cp] == '*')
					continue;

				memo[n][rp][cp] = 0;
				if (input[rp][cp] == '#')
				{
					nbfs.push(array<int, 2>{ rp, cp });
					continue;
				}
				cbfs.push(array<int, 2>{ rp, cp });
			}
		}

		m++;
	}
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int h, w;
		cin >> h >> w;

		memset(input, '.', sizeof(input));
		memset(memo, -1, sizeof(memo));

		for (int i = 1; i < h + 1; ++i)
		{
			cin >> (input[i] + 1);
			input[i][w + 1] = '.';
		}

		int pc = 0;
		flood_room(h, w, 0, 0, 0);
		for (int r = 1; r < h + 1; ++r)
		{
			for (int c = 1; c < w + 1; ++c)
			{
				if (input[r][c] == '$')
					flood_room(h, w, r, c, ++pc);
			}
		}

		int minv = 65536;
		for (int r = 1; r < h + 1; ++r)
		{
			for (int c = 1; c < w + 1; ++c)
			{
				if (memo[0][r][c] < 0 || memo[1][r][c] < 0 || memo[2][r][c] < 0 || input[r][c] == '*')
					continue;

				int v = memo[0][r][c] + memo[1][r][c] + memo[2][r][c];
				switch (input[r][c])
				{
				case '#':
					minv = min(minv, v - 2);
					break;
				default:
					minv = min(minv, v);
					break;
				}
			}
		}

		cout << minv << '\n';
	}
}