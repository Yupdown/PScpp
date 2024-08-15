#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[1000];
vector<pair<int, char>> edges[500];
int memo[1000][500];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	int m, k;
	cin >> m >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		edges[a - 1].emplace_back(b - 1, c);
		edges[b - 1].emplace_back(a - 1, c);
	}

	memset(memo, -1, sizeof(memo));
	for (const auto& p : edges[0])
		memo[0][p.first] = p.second == table[0];

	int ret = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (const auto& p : edges[j])
			{
				if (memo[i - 1][p.first] >= 0)
					memo[i][j] = max(memo[i][j], memo[i - 1][p.first] + (p.second == table[i]));
			}
			ret = max(ret, memo[i][j]);
		}
	}

	cout << ret * 10;
}