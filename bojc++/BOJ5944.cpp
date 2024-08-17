#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int result[100001];
vector<pair<int, int>> edge[100001];

int distance(int from, int to)
{
	priority_queue<pair<int, int>> pq;
	memset(result, 127, sizeof(result));
	pq.emplace(0, from);
	result[from] = 0;

	while (!pq.empty())
	{
		auto [c, n] = pq.top();
		pq.pop();
		if (-c > result[n])
			continue;
		for (const auto& [e, d] : edge[n])
		{
			int v = result[n] + d;
			if (v < result[e])
			{
				result[e] = v;
				pq.emplace(-v, e);
			}
		}
	}
	return result[to];
}

int main()
{
	FASTIO();

	int c, p, pb, pa1, pa2;
	cin >> c >> p >> pb >> pa1 >> pa2;
	for (int i = 0; i < c; ++i)
	{
		int p1, p2, d;
		cin >> p1 >> p2 >> d;
		edge[p1].emplace_back(p2, d);
		edge[p2].emplace_back(p1, d);
	}
	cout << min(distance(pb, pa1), distance(pb, pa2)) + distance(pa1, pa2);
}