#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

int64 xy[200000][2];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> xy[i][0] >> xy[i][1];

	int64 ret = 0;
	int64 xmin = LLONG_MAX, xmax = LLONG_MIN;
	for (int i = 0; i < n; ++i)
	{
		int64 x = xy[i][0] - xy[i][1];
		xmin = min(xmin, x);
		xmax = max(xmax, x);
		if (i > 0)
			ret += abs(xy[i][0] - xy[i - 1][0]) + abs(xy[i][1] - xy[i - 1][1]);
	}
	ret -= xmax - xmin;
	ret += max(0ll, xy[0][0] - xmin) + max(0ll, xmax - xy[n - 1][0]);

	cout << ret;
}