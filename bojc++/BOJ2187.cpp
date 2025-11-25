#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
tuple<int, int, int> table[1000];

int main()
{
	FASTIO();

	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		cin >> get<0>(table[i]) >> get<1>(table[i]) >> get<2>(table[i]);

	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		const auto& [x1, y1, v1] = table[i];

		int lmin = v1, lmax = v1;
		int rmin = v1, rmax = v1;

		for (int j = 0; j < n; ++j)
		{
			const auto& [x2, y2, v2] = table[j];

			int dx = x2 - x1;
			int dy = y2 - y1;
			if (dy < 0 || dy >= b)
				continue;
			if (dx <= 0 && dx >= -a + 1)
			{
				lmin = min(lmin, v2);
				lmax = max(lmax, v2);
			}
			if (dx >= 0 && dx <= a - 1)
			{
				rmin = min(rmin, v2);
				rmax = max(rmax, v2);
			}
		}
		ret = max(ret, max(rmax - rmin, lmax - lmin));
	}
	cout << ret;
}