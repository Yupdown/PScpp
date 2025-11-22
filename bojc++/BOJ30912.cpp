#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;
	vector<pair<long long, long long>> points(n);
	for (auto& [x, y] : points)
		cin >> x >> y;
	pair<long long, long long> pivot;
	cin >> pivot.first >> pivot.second;
	vector<vector<pair<long long, long long>>> buckets(2);
	for (const auto& [x, y] : points)
	{
		long long dx = x - pivot.first;
		long long dy = y - pivot.second;
		buckets[dy < 0 || (dy == 0 && dx < 0)].emplace_back(x, y);
	}
	for (auto& v : buckets)
	{
		sort(v.begin(), v.end(), [&pivot](const auto& lhs, const auto& rhs) {
			long long lhsdx = lhs.first - pivot.first;
			long long lhsdy = lhs.second - pivot.second;
			long long rhsdx = rhs.first - pivot.first;
			long long rhsdy = rhs.second - pivot.second;
			long long cross = lhsdx * rhsdy - lhsdy * rhsdx;
			if (cross == 0)
				return lhsdx * lhsdx + lhsdy * lhsdy < rhsdx * rhsdx + rhsdy * rhsdy;
			return cross > 0;
			});
		for (const auto& [x, y] : v)
			cout << x << " " << y << "\n";
	}
}