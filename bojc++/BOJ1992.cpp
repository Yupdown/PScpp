#include <iostream>

using namespace std;

string func(char map[128][128], int x, int y, int n)
{
	string result;

	if (n == 1)
		result.append(1, map[y][x]);
	else
	{
		n >>= 1;
		result.append("(");
		result.append(func(map, x, y, n));
		result.append(func(map, x + n, y, n));
		result.append(func(map, x, y + n, n));
		result.append(func(map, x + n, y + n, n));
		result.append(")");

		if (result == "(0000)")
			result = "0";
		else if (result == "(1111)")
			result = "1";
	}

	return result;
}

int main()
{
	int n;
	char map[128][128] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	cout << func(map, 0, 0, n) << endl;
	return 0;
}