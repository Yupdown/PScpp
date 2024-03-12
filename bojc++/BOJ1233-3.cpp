#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[64][64];
char tableA[64][65];
char tableB[64][65];
int dp[64][64][4];

int main()
{
	FASTIO();

	int h, w, r, c, d;
	cin >> h >> w >> r >> c >> d;

	for (int i = 0; i < h; ++i)
		cin >> tableA[i];
	for (int i = 0; i < h; ++i)
		cin >> tableB[i];

	int cnt = 0;
	int ldust = 0;
	while (true)
	{
		++cnt;

		if (table[r][c] == 1)
		{
			d = (d + tableB[r][c] - '0') % 4;
			if (dp[r][c][d] == 1)
				break;
			dp[r][c][d] = 1;
		}
		else
		{
			d = (d + tableA[r][c] - '0') % 4;
			table[r][c] = 1;
			ldust = cnt;
			memset(dp, 0, sizeof(dp));
		}

		r += "0121"[d] - '1';
		c += "1210"[d] - '1';

		if (r < 0 || r >= h || c < 0 || c >= w)
			break;
	}

	cout << ldust;
}