#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

using tp = pair<int, int>;
priority_queue<tp, vector<tp>, greater<tp>> pq;

vector<int> edges[200000];
int weights[200000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		edges[u - 1].push_back(v - 1);
		edges[v - 1].push_back(u - 1);
	}
	for (int i = 0; i < n; ++i)
		cin >> weights[i];

	int w = 0;
	pq.emplace(weights[0], 0);
	weights[0] = -1;

	while (!pq.empty())
	{
		auto [wp, c] = pq.top();
		pq.pop();
		if (c != 0 && w <= wp)
			break;
		w += wp;

		for (int e : edges[c])
		{
			if (weights[e] < 0)
				continue;
			pq.emplace(weights[e], e);
			weights[e] = -1;
		}
	}

	cout << w;
}