#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long table[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		long long n, m, k;
		cin >> n >> m >> k;

		long long w;
		cin >> w;
		for (int i = 0; i < w; ++i)
			cin >> table[i];

		vector<long long> cnt(n * m);
		for (long long i = 0; i < n; ++i)
		{
			for (long long j = 0; j < m; ++j)
				cnt[i * m + j] = max(0ll, min(min(i + 1, n - i), min(n - k + 1, k)) * min(min(j + 1, m - j), min(m - k + 1, k)));
		}

		sort(cnt.begin(), cnt.end(), greater<long long>());
		sort(table, table + w, greater<long long>());

		long long sum = 0;
		for (int i = 0; i < w; ++i)
			sum += cnt[i] * table[i];
		cout << sum << '\n';
	}
}