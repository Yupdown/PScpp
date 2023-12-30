#include <bits/stdc++.h>

using namespace std;

int input[19][19];
int dp[21][21][2][2][4];

int main()
{
	int res[3]{};

	for (int i = 0; i < 361; ++i)
		cin >> input[i / 19][i % 19];

	for (int i = 0; i < 361; ++i)
	{
		int yxj[2][2] = { i / 19, i % 19, 18 - i / 19, 18 - i % 19 };
		int x = yxj[0][1] + 1;
		int y = yxj[0][0] + 1;

		for (int j = 0; j < 2; ++j)
		{
			if (input[yxj[j][0]][yxj[j][1]] > 0)
			{
				int base = input[yxj[j][0]][yxj[j][1]] - 1;
				dp[y][x][j][base][0] = dp[y][x - 1][j][base][0] + 1;
				dp[y][x][j][base][1] = dp[y - 1][x - 1][j][base][1] + 1;
				dp[y][x][j][base][2] = dp[y - 1][x][j][base][2] + 1;
				dp[y][x][j][base][3] = dp[y - 1][x + 1][j][base][3] + 1;
			}
		}
	}

	for (int i = 0; i < 361; ++i)
	{
		int x = 18 - i / 19;
		int y = 18 - i % 19;

		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (dp[y + 1][x + 1][0][j][k] + dp[19 - y][19 - x][1][j][k] == 6)
				{
					res[0] = j + 1;
					res[1] = y + 1;
					res[2] = x + 1;
				}
			}
		}
	}

	cout << res[0] << '\n';
	if (res[0])
		cout << res[1] << ' ' << res[2];
}