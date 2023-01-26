#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char bitmask[500][500];
bool flood[500][500];

int sizeof_fragment(int n, int m, int x, int y)
{
	int r = 1;
	flood[x][y] = true;

	if (x + 1 < n && bitmask[x][y] & (1 << 0) && !flood[x + 1][y])
		r += sizeof_fragment(n, m, x + 1, y);
	if (x > 0 && bitmask[x][y] & (1 << 1) && !flood[x - 1][y])
		r += sizeof_fragment(n, m, x - 1, y);
	if (y + 1 < m && bitmask[x][y] & (1 << 2) && !flood[x][y + 1])
		r += sizeof_fragment(n, m, x, y + 1);
	if (y > 0 && bitmask[x][y] & (1 << 3) && !flood[x][y - 1])
		r += sizeof_fragment(n, m, x, y - 1);

	return r;
}

int main()
{
	FASTIO();

	memset(bitmask, 15, sizeof(bitmask));

	int n, m, t;
	cin >> n >> m >> t;

	for (int i = 0; i < t; ++i)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		bool hori = sx == ex;
		bool vert = sy == ey;

		if (hori && vert)
			continue;

		if (hori)
		{
			for (int y = min(sy, ey); y < max(sy, ey); ++y)
			{
				if (sx > 0)
					bitmask[sx - 1][y] &= ~(1 << 0);
				if (sx < n)
					bitmask[sx][y] &= ~(1 << 1);
			}
		}

		if (vert)
		{
			for (int x = min(sx, ex); x < max(sx, ex); ++x)
			{
				if (sy > 0)
					bitmask[x][sy - 1] &= ~(1 << 2);
				if (sy < m)
					bitmask[x][sy] &= ~(1 << 3);
			}
		}
	}

	int smax = 0;
	int smin = 250000;

	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{
			if (flood[x][y])
				continue;

			int s = sizeof_fragment(n, m, x, y);
			smax = max(smax, s);
			smin = min(smin, s);
		}
	}

	cout << smax << endl;
	cout << smin << endl;
}