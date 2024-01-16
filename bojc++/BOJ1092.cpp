#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int p[64], w[10000], cnt[64];

int main()
{
	FASTIO();

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> w[i];

	sort(p, p + n, greater<int>());
	sort(w, w + m, greater<int>());

	if (p[0] < w[0])
	{
		cout << -1;
		return 0;
	}

	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j < m && w[j] > p[i + 1])
			++j, ++cnt[i];
	}

	int t = 0;
	while (m > 0)
	{
		for (int i = 0, j = 0; i < n; ++i)
		{
			++j;
			int v = min(cnt[i], j);
			cnt[i] -= v;
			m -= v;
			j -= v;
		}
		++t;
	}

	cout << t;
}