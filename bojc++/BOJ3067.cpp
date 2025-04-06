#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[1 << 14];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		vector<int> table;
		for (int i = 0; i < n; ++i)
			cin >> table.emplace_back();
		cin >> m;
		memset(memo, 0, sizeof(memo));
		memo[0] = 1;
		for (const int& p : table)
		{
			for (int i = p; i <= m; ++i)
				memo[i] += memo[i - p];
		}
		cout << memo[m] << "\n";
	}
}