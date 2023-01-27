#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int cache[50][5];

int get_value(int x, int y)
{
	int level = max(abs(x), abs(y));
	int base = level * 2 - 1;
	base *= base;

	if (x == level && y != level)
		return base - y + level;
	if (y == -level)
		return base - x + level * 3;
	if (x == -level)
		return base + y + level * 5;
	if (y == level)
		return base + x + level * 7;
	return 1;
}

int main()
{
	FASTIO();

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int vmax = 0;
	for (int i = r1; i <= r2; ++i)
	{
		for (int j = c1; j <= c2; ++j)
			vmax = max(vmax, cache[i - r1][j - c1] = get_value(j, i));
	}

	int w = 1;
	for (int n = vmax; n > 0; n /= 10)
		++w;

	for (int i = 0; i <= r2 - r1; ++i)
	{
		for (int j = 0; j <= c2 - c1; ++j)
			cout << setw(j > 0 ? w : w - 1) << cache[i][j];
		cout << '\n';
	}
}