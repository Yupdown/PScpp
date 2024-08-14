#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int INF = 0x01010101;
int memo[1001][101];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> cnts[1000];
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			if (a < b)
				swap(a, b);
			for (int j = 0; j < a - b + 1; ++j)
				cnts[i].push_back(b);
			for (int j = b - 1; j > 0; --j)
			{
				cnts[i].push_back(j);
				cnts[i].push_back(j);
			}
			cnts[i].push_back(0);
			for (int j = 1; j < cnts[i].size(); ++j)
				cnts[i][j] += cnts[i][j - 1];
		}

		memset(memo, 1, sizeof(memo));
		memo[0][0] = 0;
		for (int i = 1; i - 1 < n; ++i)
		{
			for (int j = 0; j <= k; ++j)
				memo[i][j] = memo[i - 1][j];
			for (int j = k; j >= 0; --j)
			{
				if (memo[i - 1][j] < INF)
				{
					for (int l = 0; l < cnts[i - 1].size(); ++l)
					{
						if (j + l + 1 <= k)
							memo[i][j + l + 1] = min(memo[i][j + l + 1], memo[i - 1][j] + cnts[i - 1][l]);
					}
				}
			}
		}

		cout << (memo[n][k] < INF ? memo[n][k] : -1) << '\n';
	}
}