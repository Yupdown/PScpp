#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
struct v2d { long long x, y; };

int square_check(v2d p1, v2d p2, v2d p3, v2d p4)
{
	if (p1.x + p2.x != p3.x + p4.x || p1.y + p2.y != p3.y + p4.y)
		return 0;

	v2d v1, v2;
	v1.x = p2.x - p1.x;
	v1.y = p2.y - p1.y;
	v2.x = p4.x - p3.x;
	v2.y = p4.y - p3.y;

	return v1.x * v1.x + v1.y * v1.y == v2.x * v2.x + v2.y * v2.y && v1.x * v2.x + v1.y * v2.y == 0;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		v2d pos[4];
		for (int i = 0; i < 4; ++i)
			cin >> pos[i].x >> pos[i].y;

		int result = 0;
		result |= square_check(pos[0], pos[1], pos[2], pos[3]);
		result |= square_check(pos[0], pos[2], pos[1], pos[3]);
		result |= square_check(pos[0], pos[3], pos[1], pos[2]);

		cout << result << '\n';
	}
}