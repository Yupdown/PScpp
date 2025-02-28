#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int64_t w, h, k, t;
	cin >> w >> h >> k >> t;

	int64_t s = 1ll;
	for (int i = 0; i < k; ++i)
	{
		int64_t x, y;
		cin >> x >> y;

		int64_t dx = min(w, x + t) - max((int64_t)1, x - t) + 1ll;
		int64_t dy = min(h, y + t) - max((int64_t)1, y - t) + 1ll;

		s = s * dx % 998'244'353ll;
		s = s * dy % 998'244'353ll;
	}

	cout << s;
}