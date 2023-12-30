#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int n, p, input[16][16], memo[1 << 16];

int Function(int cnt, int bitmask)
{
	if (cnt >= p)
		return memo[bitmask] = 0;
	if (memo[bitmask] >= 0)
		return memo[bitmask];

	int res = 1024;
	for (int next = 0; next < n; ++next)
	{
		if (bitmask & 1 << next)
			continue;

		int means = -1;
		for (int i = 0; i < n; ++i)
		{
			if (bitmask & 1 << i)
				means = (means < 0 || input[i][next] < input[means][next]) ? i : means;
		}
		res = min(res, Function(cnt + 1, bitmask | 1 << next) + input[means][next]);
	}

	return memo[bitmask] = res;
}

int main()
{
	FASTIO();

	cin >> n;
	for (int i = 0; i < n * n; ++i)
		cin >> input[i / n][i % n];

	string buffer;
	cin >> buffer >> p;

	int cnt = 0, bitmask = 0;
	for (int i = 0; i < n; ++i)
	{
		if (buffer[i] == 'Y')
		{
			bitmask |= 1 << i;
			++cnt;
		}
	}

	memset(memo, -1, sizeof(memo));

	if ((cnt && p <= n) || (!cnt && !p))
		cout << Function(cnt, bitmask);
	else
		cout << -1;
}