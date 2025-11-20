#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		priority_queue<pair<int, int>> pq;
		vector<pair<int, int>> pairs;
		for (int i = 0; i < n; ++i)
			pq.emplace(table[i], i);
		int jmax = -1;
		int vmin = 200000;
		for (int i = 0; i < n; ++i)
		{
			if (vmin > table[i])
			{
				if (jmax > i)
					pairs.emplace_back(table[i], table[jmax]);
				if (!pq.empty())
				{
					while (pq.top().first > table[i])
					{
						auto [v, j] = pq.top();
						pq.pop();
						jmax = max(jmax, j);
						pairs.emplace_back(table[i], v);
					}
					pq.pop();
				}
			}
			vmin = min(vmin, table[i]);
		}
		if (pairs.size() == n - 1)
		{
			cout << "Yes\n";
			for (const auto& [u, v] : pairs)
				cout << u << " " << v << "\n";
		}
		else
			cout << "No\n";
	}
}