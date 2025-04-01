#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

map<pair<int64, int64>, int> memo[2];

int main()
{
	FASTIO();

	int64 x, y;
	int n;
	cin >> x >> y >> n;
	for (int i = 0; i < n; ++i)
	{
		int64 xi, yi;
		cin >> xi >> yi;
		if (yi >= y || xi == x)
			continue;
		int64 dx = xi - x;
		int64 dy = yi - y;
		int64 num = dy;
		int64 den = dx * dx;
		int64 g = gcd(num, den);
		num /= g;
		den /= g;
		memo[dx > 0][make_pair(num, den)]++;
	}
	int ret = 0;
	for (const auto& m : memo)
	{
		for (const auto& [k, v] : m)
			ret = max(ret, v);
	}
	cout << ret;
}