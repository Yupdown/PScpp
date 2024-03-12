#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[500][500];

int main()
{
	FASTIO();

	int h;
	cin >> h;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j <= i; ++j)
			cin >> memo[i][j];
	}

	int res = 0;
	for (int i = 1; i < h; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			memo[i][j] += max(memo[i - 1][j], j > 0 ? memo[i - 1][j - 1] : 0);
			res = max(res, memo[i][j]);
		}
	}

	cout << res;
}