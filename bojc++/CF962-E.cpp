#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr long long MOD = 1000000007;
long long cnt[1 << 19];
long long y[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size();

		memset(y, 0, sizeof(y));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0, v = 1 << 18; i < n; ++i)
		{
			cnt[v] += i + 1;
			v += s[i] == '1' ? 1 : -1;
			y[i] = cnt[v];
		}

		long long ret = 0;
		for (int i = 0; i < n; ++i)
		{
			ret += y[i] * (n - i);
			ret %= MOD;
		}

		cout << ret << '\n';
	}
}