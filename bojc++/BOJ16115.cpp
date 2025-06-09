#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
using int64 = long long;

pair<int64, int64> points[300000];

int main()
{
	FASTIO();
	PRECISION(6);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> points[i].first >> points[i].second;
	// sort points by their distances from origin, the order must be sustained
	stable_sort(points, points + n, [](const auto& lhs, const auto& rhs) { return lhs.first * lhs.first + lhs.second * lhs.second > rhs.first * rhs.first + rhs.second * rhs.second; });
	// truncate points whose distances are less than maximum
	for (int i = 0; i < n; ++i)
	{
		if (points[0].first * points[0].first + points[0].second * points[0].second > points[i].first * points[i].first + points[i].second * points[i].second)
		{
			n = i;
			break;
		}
	}
	if (n == 1)
		cout << 360;
	else
	{
		double ret = fmod(atan2(points[0].second, points[0].first) - atan2(points[n - 1].second, points[n - 1].first) + M_PI * 2, M_PI * 2);
		for (int i = 0; i < n - 1; ++i)
			ret = max(ret, fmod(atan2(points[i + 1].second, points[i + 1].first) - atan2(points[i].second, points[i].first) + M_PI * 2, M_PI * 2));
		cout << ret / M_PI * 180;
	}
}