#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[100][70];
int memo[100][70];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> cand;
	for (int i = 0; i < n * m; ++i)
	{
		cin >> table[i / m][i % m];
		cand.emplace_back(i / m, i % m);
	}
	sort(cand.begin(), cand.end(), [](const auto& lhs, const auto& rhs) { return table[lhs.first][lhs.second] > table[rhs.first][rhs.second]; });

	int ret = 0;
	for (const auto& c : cand)
	{
		auto [i0, j0] = c;
		if (memo[i0][j0])
			continue;
		memo[i0][j0] = 1;
		queue<pair<int, int>> q;
		q.emplace(i0, j0);
		
		while (!q.empty())
		{
			auto [i, j] = q.front();
			q.pop();
			for (int d = 0; d < 8; ++d)
			{
				int ip = i + "10001222"[d] - '1';
				int jp = j + "22100012"[d] - '1';

				if (ip < 0 || ip >= n || jp < 0 || jp >= m)
					continue;
				if (memo[ip][jp])
					continue;
				if (table[ip][jp] > table[i][j])
					continue;

				memo[ip][jp] = 1;
				q.emplace(ip, jp);
			}
		}
		ret++;
	}

	cout << ret;
}