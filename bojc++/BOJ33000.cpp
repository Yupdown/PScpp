#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	long long a, b;
	cin >> a >> b;
	pair<int, long long> ret = make_pair(__builtin_popcountll(a), a);
	for (long long n = 1LL << 62; n > 0; n >>= 1)
	{
		if (a & n)
			continue;
		long long c = a + n - (a & n - 1);
		if (c <= b)
			ret = min(ret, make_pair(__builtin_popcountll(c), c));
	}
	cout << ret.second;
}