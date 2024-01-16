#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[1 << 19];
priority_queue<pair<int, int>> pq;

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k >> table;

	for (int i = 0; i < k + 1; ++i)
		pq.push(make_pair(table[i], -i));

	int index = 0;
	for (int i = k; i < n; ++i)
	{
		if (i > k)
			pq.push(make_pair(table[i], -i));
		while (!pq.empty() && -pq.top().second < index)
			pq.pop();
		cout << static_cast<char>(pq.top().first);
		index = -pq.top().second;
		pq.pop();
	}
}