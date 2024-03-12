#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> table[1000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;

	sort(table, table + n);

	int dist = INT_MAX;
	for (int i = 1; i < n; ++i)
	{
		if (table[i - 1].second != table[i].second)
			dist = min(dist, table[i].first - table[i - 1].first);
	}

	int cnt = 0, i = 0;
	while (i < n)
	{
		if (!table[i].second)
		{
			++i;
			continue;
		}
		while (i < n && table[i].second)
		{
			++i;
			if (table[i].first - table[i - 1].first >= dist)
				break;
		}
		++cnt;
	}

	cout << cnt;
}