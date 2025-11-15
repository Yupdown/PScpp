#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
tuple<long long, long long, long long> pwdi[200000];

long long ternary_search(long long min, long long max, long long epsilon, function<long long(long long)> callback)
{
	long long lo = min, hi = max;

	while (hi - lo > epsilon)
	{
		long long p = (lo * 2 + hi) / 3;
		long long q = (lo + hi * 2) / 3;

		long long dp = callback(p);
		long long dq = callback(q);

		if (dp < dq)
			hi = q;
		else
			lo = p;
	}

	return lo;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		auto& [p, w, d] = pwdi[i];
		cin >> p >> w >> d;
	}
	sort(pwdi, pwdi + n);
	auto costFunc = [&](long long x) {
		long long ret = 0;
		for (int i = 0; i < n; ++i)
		{
			auto& [p, w, d] = pwdi[i];
			ret += max(0LL, w * (abs(p - x) - d));
		}
		return ret;
	};
	auto pos = ternary_search(get<0>(pwdi[0]), get<0>(pwdi[n - 1]), 16, costFunc);
	long long ret = costFunc(pos);
	for (long long x = pos; x <= pos + 16; x++)
		ret = min(ret, costFunc(x));
	cout << ret;
}