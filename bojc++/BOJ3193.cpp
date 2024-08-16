#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[1000][1001];
int memo[1000][1000][4];

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> table[i];
	
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (table[i][j] == 'L')
			{
				y = i;
				x = j;
				table[i][j] = '.';
			}
			memo[i][j][2] = i > 0 && table[i - 1][j] != 'X' ? memo[i - 1][j][2] : i;
			memo[i][j][1] = j > 0 && table[i][j - 1] != 'X' ? memo[i][j - 1][1] : j;
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			memo[i][j][0] = i < n - 1 && table[i + 1][j] != 'X' ? memo[i + 1][j][0] : i;
			memo[i][j][3] = j < n - 1 && table[i][j + 1] != 'X' ? memo[i][j + 1][3] : j;
		}
	}

	int o = 0;
	y = memo[y][x][0];
	for (int i = 0; i < k; ++i)
	{
		char c;
		cin >> c;
		o = (o + (c == 'L' ? 1 : 3)) % 4;
		if (o & 1)
			x = memo[y][x][o];
		else
			y = memo[y][x][o];
	}

	table[y][x] = 'L';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			switch (o)
			{
			case 0:
				cout << table[i][j];
				break;
			case 1:
				cout << table[j][n - i - 1];
				break;
			case 2:
				cout << table[n - i - 1][n - j - 1];
				break;
			case 3:
				cout << table[n - j - 1][i];
				break;
			}
		}
		cout << '\n';
	}
}