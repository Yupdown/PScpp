#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using pll = pair<long long, long long>;

inline pll func(long long n, long long x)
{
	long long y = (n + x - 1) / x;
	return make_pair(x * 44 + 4, y * 10 + 2);
}

inline pll sel(const pll& lhs, const pll& rhs)
{
	auto m1 = lhs.first * lhs.second;
	auto m2 = rhs.first * rhs.second;
	if (m1 == m2)
		return abs(lhs.first - lhs.second) < abs(rhs.first - rhs.second) ? lhs : rhs;
	return m1 < m2 ? lhs : rhs;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		long long n;
		cin >> n;
		n = (n + 4) / 5;
		auto ret = func(n, 1);
		for (long long x = 2; x * x <= n; ++x)
			ret = sel(ret, func(n, x));
		cout << max(ret.first, ret.second) << " X " << min(ret.first, ret.second) << " = " << ret.first * ret.second << '\n';
	}
}