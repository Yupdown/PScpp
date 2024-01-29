#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

tuple<int, int, int, int> query[100000];
priority_queue<pair<int, int>> pq;


int main()
{
	FASTIO();

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; ++i)
	{
		int a, b, x;
		cin >> a >> b >> x;
		`query[i] = make_tuple(a - 1, b - 1, x, i);
	}

	sort(query, query + q);
	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j < n && get<0>(query[j]) <= i)
		{
			pq.push(make_pair(-get<3>(query[j]), j));
			++j;
		}

		while (!pq.empty() && get<1>(query[pq.top().second]) < i)
			pq.pop();

		if (!pq.empty())
			cout << get<2>(query[pq.top().second]) << ' ';
		else
			cout << "0 ";
	}
}