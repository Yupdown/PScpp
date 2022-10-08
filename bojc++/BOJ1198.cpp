#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
struct vector2d { int x, y; };

inline int sizeof_triangle(vector2d p1, vector2d p2, vector2d p3)
{
	return abs((p1.y - p2.y) * (p3.x - p2.x) - (p1.x - p2.x) * (p3.y - p2.y));
}

int main()
{
	FASTIO();

	int n;
	vector2d vert[35];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> vert[i].x >> vert[i].y;

	int smax = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
				smax = max(smax, sizeof_triangle(vert[i], vert[j], vert[k]));
		}
	}

	cout << smax * 0.5 << '\n';
	return 0;
}