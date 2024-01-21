#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int64_t n, k, q;
	cin >> n >> k >> q;

	while (q-- > 0)
	{
		int64_t x, y;
		cin >> x >> y;

		if (k == 1)
			cout << abs(x - y) << '\n';
		else
		{
			vector<int> xp;
			while (x > 1)
			{
				xp.push_back(x);
				x = (x + k - 2) / k;
			}
			vector<int> yp;
			while (y > 1)
			{
				yp.push_back(y);
				y = (y + k - 2) / k;
			}
			while (!xp.empty() && !yp.empty() && xp.back() == yp.back())
			{
				xp.pop_back();
				yp.pop_back();
			}

			cout << xp.size() + yp.size() << '\n';
		}
	}
}