#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

pair<int64, int64> ternary_search(int64 min, int64 max, int64(*callback)(int64))
{
	int64 lo = min, hi = max;

	while (hi - lo > 2)
	{
		int64 p = (lo * 2 + hi) / 3;
		int64 q = (lo + hi * 2) / 3;

		int64 dp = callback(p);
		int64 dq = callback(q);

		if (dp < dq)
			hi = q;
		else
			lo = p;
	}

	int64 x = callback(lo) < callback(lo + 1) ? lo : lo + 1;
	return make_pair(x, callback(x));
}

int n, input[100000];

int64 callback_solution(int64 v)
{
	int64 r = 0;
	for (int i = 0; i < n; ++i)
		r += abs(v * i - input[i]);
	return r;
}

int main()
{
	FASTIO();

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> input[i];

	cout << ternary_search(0, 1 << 30, callback_solution).second;
}