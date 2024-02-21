#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int xy[200000][2];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> xy[i][0] >> xy[i][1];

	int ret = 0;
	int bmin = INT_MAX, bmax = INT_MIN;
	for (int i = 1; i < n; ++i)
	{
		int dx = xy[i][0] - xy[i - 1][0];
		int dy = xy[i][1] - xy[i - 1][1];

		if (dx < 0 || dy > 0)
			ret += dy - dx;
	}
}