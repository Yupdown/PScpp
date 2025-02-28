#include <iostream>
#include <cstring>

using namespace std;

int memo[80][100][100];
int offset[20][2];

int main()
{
	char map[128][128];
	char word[128];

	int n, m, k, l;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		cin >> map[i];
	cin >> word;
	l = strlen(word);

	for (int i = 0; i < k; ++i)
	{
		offset[i * 4][0] = i + 1;
		offset[i * 4 + 1][0] = -(i + 1);
		offset[i * 4 + 2][1] = i + 1;
		offset[i * 4 + 3][1] = -(i + 1);
	}

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (map[y][x] == word[0])
				memo[0][y][x] = 1;
		}
	}

	for (int i = 1; i < l; ++i)
	{
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < m; ++x)
			{
				if (map[y][x] != word[i])
					continue;

				for (int j = 0; j < k * 4; ++j)
				{
					int tx = x + offset[j][0];
					int ty = y + offset[j][1];

					if (tx < 0 || tx >= m)
						continue;
					if (ty < 0 || ty >= n)
						continue;

					memo[i][y][x] += memo[i - 1][ty][tx];
				}
			}
		}
	}

	int result = 0;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
			result += memo[l - 1][y][x];
	}

	cout << result << endl;
	return 0;
}