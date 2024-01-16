#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[750][751];
int memo[750][750][2];

int main()
{
	FASTIO();

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; ++i)
		cin >> table[i];

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			for (int k = 0; k < 4; ++k)
				memo[i][j][k] = table[i][j] == '1';
		}
	}

	for (int i = 1; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (table[i][j] != '1')
				continue;
			if (j > 0)
				memo[i][j][0] += memo[i - 1][j - 1][0];
			if (j + 1 < c)
				memo[i][j][1] += memo[i - 1][j + 1][1];
		}
	}

	int smax = 0;

	for (int s = 1; s * 2 <= min(r, c) + 1; ++s)
	{
		int d = s - 1;
		for (int i = d; i < r - d; ++i)
		{
			for (int j = d; j < c - d; ++j)
			{
				if (memo[i][j + d][0] < s)
					continue;
				if (memo[i][j - d][1] < s)
					continue;
				if (memo[i + d][j][0] < s)
					continue;
				if (memo[i + d][j][1] < s)
					continue;
				smax = s;
			}
		}
	}

	cout << smax;
}