#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> table[1000];
priority_queue<int> pq;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;

	sort(table, table + n, greater<pair<int, int>>());

	int sum = 0;
	for (int t = 1000, i = 0; t > 0; --t)
	{
		while (i < n && table[i].first >= t)
			pq.push(table[i++].second);

		if (pq.empty())
			continue;

		sum += pq.top();
		pq.pop();
	}

	cout << sum;
}