#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<tuple<int, int, long long>> edges[1 << 10];

pair<long long, int> dijkstra(int from, int to)
{
	// cost, flights, city, last flight respectively
	using pqt = tuple<long long, int, int, int>;
	priority_queue<pqt, vector<pqt>, greater<pqt>> pq;
	// cost, flights respectively
	vector<vector<pair<long long, int>>> memo(1 << 10);
	for (auto& memo_sub : memo)
		memo_sub.resize(1 << 10, make_pair(LLONG_MAX, INT_MAX));
	memo[from][1000] = make_pair(0, 0);
	pq.emplace(0, 0, from, 1000);
	while (!pq.empty())
	{
		auto [lc, nf, node, lf] = pq.top();
		pq.pop();
		if (make_pair(lc, nf) > memo[node][lf])
			continue;
		for (const auto& [node_next, cf, c] : edges[node])
		{
			auto p = memo[node][lf];
			if (lf != cf)
				p.first += c;
			p.second += 1;
			if (p < memo[node_next][cf])
			{
				memo[node_next][cf] = p;
				pq.emplace(p.first, p.second, node_next, cf);
			}
		}
	}

	auto ret = make_pair(LLONG_MAX, INT_MAX);
	for (int i = 0; i < 1000; ++i)
		ret = min(ret, memo[to][i]);
	return ret.first < LLONG_MAX ? ret : make_pair(-1LL, -1);
}

int main()
{
	FASTIO();

	int a, b, n;
	cin >> a >> b >> n;

	for (int i = 0; i < n; ++i)
	{
		long long c;
		int nc;
		cin >> c >> nc;
		int lc;
		cin >> lc;
		while (--nc)
		{
			int cc;
			cin >> cc;
			edges[lc].emplace_back(cc, i, c);
			lc = cc;
		}
	}
	
	auto [r1, r2] = dijkstra(a, b);
	cout << r1 << " " << r2;
}