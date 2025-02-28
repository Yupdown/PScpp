#include <iostream>
#include <cstring>

using namespace std;

void func(char map[128][128], int visited[128][128], int width, int height, int x, int y, char target)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return;
	if (map[x][y] != target || visited[x][y])
		return;

	visited[x][y] = 1;

	func(map, visited, width, height, x + 1, y, target);
	func(map, visited, width, height, x - 1, y, target);
	func(map, visited, width, height, x, y + 1, target);
	func(map, visited, width, height, x, y - 1, target);
}

int main()
{
	int n, c0 = 0, c1 = 0;
	cin >> n;

	char map[128][128] = { 0 };
	int visited[128][128] = { 0 };

	for (int i = 0; i < n; i++)
		cin >> map[i];

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (!visited[x][y])
			{
				func(map, visited, n, n, x, y, map[x][y]);
				c0++;
			}
		}
	}

	for (int i = 0; i < n * n; i++)
	{
		char* dest = &map[i / n][i % n];
		*dest = *dest == 'G' ? 'R' : *dest;
	}
	memset(visited, 0, sizeof(visited));

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (!visited[x][y])
			{
				func(map, visited, n, n, x, y, map[x][y]);
				c1++;
			}
		}
	}

	cout << c0 << ' ' << c1 << endl;
	return 0;
}