#include <iostream>
#include <math.h>

using namespace std;

int func(char map[32][32], bool flag[26], int width, int height, int x, int y, int depth)
{
	char alphabet = map[y][x] - 'A';

	if (x < 0 || x >= width || y < 0 || y >= height)
		return depth - 1;
	if (flag[alphabet])
		return depth - 1;

	int result = 0;
	flag[alphabet] = true;

	result = max(result, func(map, flag, width, height, x + 1, y, depth + 1));
	result = max(result, func(map, flag, width, height, x - 1, y, depth + 1));
	result = max(result, func(map, flag, width, height, x, y + 1, depth + 1));
	result = max(result, func(map, flag, width, height, x, y - 1, depth + 1));

	flag[alphabet] = false;
	return result;
}

int main()
{
	char map[32][32];
	bool flag[26] = { false };
	int r, c;

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> map[i];

	cout << func(map, flag, c, r, 0, 0, 1) << endl;
	return 0;
}