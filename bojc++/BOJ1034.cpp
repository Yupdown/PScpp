#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[50][51];
map<int64_t, int> cnt;

int main()
{
	FASTIO();

	int n, m, k;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	cin >> k;

	for (int i = 0; i < n; ++i)
	{
		int64_t v = 0;
		int c = 0;
		for (int j = 0; j < m; ++j)
		{
			if (table[i][j] != '0')
				continue;
			v += 1ll << j;
			++c;
		}

		if (c <= k && c % 2 == k % 2)
		{
			if (cnt.find(v) == cnt.end())
				cnt[v] = 0;
			++cnt[v];
		}
	}

	int cmax = 0;
	for (auto& c : cnt)
		cmax = max(cmax, c.second);
	cout << cmax;
}