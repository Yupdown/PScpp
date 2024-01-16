#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

tuple<int, int, int> points[50];

inline int orientation(int ax, int ay, int bx, int by, int cx, int cy)
{
	return (by - ay) * (cx - bx) - (bx - ax) * (cy - by);
}

inline int dot(int ax, int ay, int bx, int by)
{
	return ax * bx + ay * by;
}

int main()
{
	FASTIO();

	int n, vsum = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x, y, v;
		cin >> x >> y >> v;
		points[i] = make_tuple(x, y, v);
		vsum += v;
	}

	int diff = vsum;
	for (int i = 0; i < n; ++i)
	{
		auto [ix, iy, iv] = points[i];
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			auto [jx, jy, jv] = points[j];
			int vpsum1 = 0;
			int vpsum2 = 0;
			for (int k = 0; k < n; ++k)
			{
				auto [kx, ky, kv] = points[k];
				int o = orientation(ix, iy, jx, jy, kx, ky);
				int d = dot(jx - ix, jy - iy, kx - ix, ky - iy);
				if (o > 0 || (!o && d >= 0))
					vpsum1 += kv;
				if (o > 0 || (!o && d <= 0))
					vpsum2 += kv;
			}
			diff = min(diff, abs(vsum - vpsum1 * 2));
			diff = min(diff, abs(vsum - vpsum2 * 2));
		}
	}

	cout << diff;
}