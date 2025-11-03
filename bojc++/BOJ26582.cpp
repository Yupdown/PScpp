#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	vector<pair<int, int>> table;
	int t;
	cin >> t;
	while (t--)
	{
		int n, w;
		cin >> n >> w;
		table.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> table[i].first >> table[i].second;
		map<int, int, greater<int>> memo;
		memo[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			for (const auto& [wp, vp] : memo)
			{
				int wpp = wp + table[i].second;
				if (wpp > w)
					continue;
				memo[wpp] = max(memo[wpp], vp + table[i].first);
			}
		}
		int ret = 0;
		for (const auto& [wp, vp] : memo)
			ret = max(ret, vp);
		cout << ret << '\n';
	}
}