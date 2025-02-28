#include <iostream>

using namespace std;

void func(int map[50][50], int width, int height, int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return;
	if (map[x][y] == 0)
		return;

	map[x][y] = 0;

	func(map, width, height, x + 1, y);
	func(map, width, height, x - 1, y);
	func(map, width, height, x, y + 1);
	func(map, width, height, x, y - 1);
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, k, c = 0;
		cin >> m >> n >> k;

		int map[50][50] = { 0 };

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;

			map[x][y] = 1;
		}

		for (int x = 0; x < m; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (map[x][y])
				{
					func(map, m, n, x, y);
					c++;
				}
			}
		}

		cout << c << endl;
	}
}