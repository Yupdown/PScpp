#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

vector<pair<int64, int64>> points;

int64 distance_squared(const pair<int64, int64>& lhs, const pair<int64, int64>& rhs)
{
	int64 dx = lhs.first - rhs.first;
	int64 dy = lhs.second - rhs.second;
	return dx * dx + dy * dy;
}

int main()
{
	FASTIO();

	int n;
	pair<int64, int64> p1, p2;
	cin >> n >> p1.first >> p1.second >> p2.first >> p2.second;
	for (int i = 0; i < n; ++i)
	{
		int64 x, y;
		cin >> x >> y;
		points.emplace_back(x, y);
	}

	sort(points.begin(), points.end(), [&p1](const auto& lhs, const auto& rhs) {
		return distance_squared(lhs, p1) > distance_squared(rhs, p1);
		});

	int64 ret = distance_squared(points[0], p1);
	int64 r2 = 0;
	for (int i = 1; i < n; ++i)
	{
		r2 = max(r2, distance_squared(points[i - 1], p2));
		ret = min(ret, distance_squared(points[i], p1) + r2);
	}
	r2 = max(r2, distance_squared(points[n - 1], p2));
	ret = min(ret, r2);
	cout << ret;
}