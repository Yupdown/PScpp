#include <iostream>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

int get_num_points(int64 x1, int64 y1, int64 r1, int64 x2, int64 y2, int64 r2)
{
	int64 dist_sqr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	int64 radiusSqrA = (r1 + r2) * (r1 + r2);
	int64 radiusSqrB = (r1 - r2) * (r1 - r2);

	if (dist_sqr < radiusSqrA && dist_sqr > radiusSqrB)
		return 2;
	else if (dist_sqr > radiusSqrA || dist_sqr < radiusSqrB)
		return 0;
	else
		return dist_sqr != 0 || radiusSqrA == 0 ? 1 : -1;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int64 x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << get_num_points(x1, y1, r1, x2, y2, r2) << '\n';
	}

	return 0;
}