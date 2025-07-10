#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[128];
pair<int, int> memov[1 << 18];
pair<int, int> memoh[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long n, m;
		cin >> n >> m;

		memset(memo, 0, 512);
		memset(memoh, 0, 8 * n);
		memset(memov, 0, 8 * m);

		vector<vector<int>> table(n);
		for (auto& v : table)
			v.resize(m);

		int vmax = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int v;
				cin >> v;
				table[i][j] = v;
				if (v > memoh[i].first)
					memoh[i] = make_pair(v, 1);
				else if (v == memoh[i].first)
					memoh[i].second++;
				if (v > memov[j].first)
					memov[j] = make_pair(v, 1);
				else if (v == memov[j].first)
					memov[j].second++;
				memo[v]++;
				vmax = max(vmax, v);
			}
		}
		
		int delta = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (memoh[i].first == vmax && memov[j].first == vmax)
				{
					if (memoh[i].second + memov[j].second == memo[vmax] + (table[i][j] == vmax))
						delta = -1;
				}
			}
		}
		cout << vmax + delta << "\n";
	}
}