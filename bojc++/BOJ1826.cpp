#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> stations[10000];
priority_queue<int> pq;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> stations[i].first >> stations[i].second;

	int l, p;
	cin >> l >> p;

	sort(stations, stations + n);

	int x = p, i = 0, cnt = 0;
	while (x < l)
	{
		while (i < n && stations[i].first <= x)
			pq.push(stations[i++].second);

		if (pq.empty())
		{
			cout << -1;
			return 0;
		}

		x += pq.top();
		pq.pop();

		++cnt;
	}

	cout << cnt;
}