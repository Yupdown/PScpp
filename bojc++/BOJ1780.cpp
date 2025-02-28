#include <iostream>

using namespace std;

int func(int* out, int map[2187][2187], int x, int y, int n)
{
	if (n == 1)
	{
		out[map[x][y] + 1]++;
		return map[x][y];
	}

	n /= 3;
	int first = func(out, map, x, y, n);
	bool condition = true;
	for (int i = 1; i < 9; i++)
		condition &= first == func(out, map, x + i % 3 * n, y + i / 3 * n, n);

	if (condition)
		out[first + 1] -= 8;
	return condition ? first : -2;
}

int main()
{
	int n;
	int map[2187][2187] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	int result[3] = { 0 };
	func(result, map, 0, 0, n);

	cout << result[0] << endl << result[1] << endl << result[2] << endl;
	return 0;
}