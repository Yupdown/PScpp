#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(char map[32][32], int width, int height, int x, int y)
{
	int result = 1;

	if (x < 0 || x >= width || y < 0 || y >= height)
		return 0;
	if (map[x][y] == '0')
		return 0;

	map[x][y] = '0';

	result += func(map, width, height, x + 1, y);
	result += func(map, width, height, x - 1, y);
	result += func(map, width, height, x, y + 1);
	result += func(map, width, height, x, y - 1);

	return result;
}

int main()
{
	int n;
	cin >> n;

	char map[32][32] = { 0 };

	for (int i = 0; i < n; i++)
		cin >> map[i];

	vector<int> result;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (map[x][y] == '1')
				result.push_back(func(map, n, n, x, y));
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}