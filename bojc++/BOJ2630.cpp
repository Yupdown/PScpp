#include <iostream>

using namespace std;

int func(int& r0, int& r1, int map[128][128], int x, int y, int n)
{
	if (n == 1)
	{
		if (map[x][y])
			r1++;
		else
			r0++;

		return map[x][y];
	}

	n >>= 1;
	int s1 = func(r0, r1, map, x, y, n);
	int s2 = func(r0, r1, map, x + n, y, n);
	int s3 = func(r0, r1, map, x, y + n, n);
	int s4 = func(r0, r1, map, x + n, y + n, n);

	bool condition = s1 == s2 && s3 == s4 && s1 == s3;

	if (condition)
	{
		if (s1 == 1)
			r1 -= 3;
		else if (s1 == 0)
			r0 -= 3;
	}

	return condition ? s1 : -1;;
}

int main()
{
	int n;
	int map[128][128] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	int r0 = 0, r1 = 0;
	func(r0, r1, map, 0, 0, n);

	cout << r0 << endl << r1 << endl;
	return 0;
}