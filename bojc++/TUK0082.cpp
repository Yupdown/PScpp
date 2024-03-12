#include <iostream>

using namespace std;

void func(char map[128][128], int width, int height, int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return;
	if (map[x][y] == '.')
		return;
	map[x][y] = '.';

	func(map, width, height, x + 1, y);
	func(map, width, height, x - 1, y);
	func(map, width, height, x, y + 1);
	func(map, width, height, x, y - 1);
}

int main()
{
	int m, n, c = 0;
	cin >> m >> n;

	char map[128][128] = { 0 };
	for (int i = 0; i < m; ++i)
		cin >> map[i];

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (map[x][y] == '*')
			{
				func(map, m, n, x, y);
				c++;
			}
		}
	}

	cout << c << endl;
}