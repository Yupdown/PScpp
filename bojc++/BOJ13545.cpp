#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100001];
int memo[2][200001];
array<int, 4> queries[100000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n;
	for (int i = 1; i < n + 1; ++i)
		cin >> table[i];
	table[0] = n;
	for (int i = 1; i < n + 1; ++i)
		table[i] += table[i - 1];
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		queries[i][0] = i;
		cin >> queries[i][1] >> queries[i][2];
		queries[i][1]--;
	}

	int itv = sqrt(n);
	sort(queries, queries + m, [itv](const auto& lhs, const auto& rhs) { return lhs[1] / itv == rhs[1] / itv ? lhs[2] < rhs[2] : lhs[1] < rhs[1]; });

	int q, pp, lpmax;
	for (int i = 0; i < m; ++i)
	{
		if (i == 0 || queries[i - 1][1] / itv < queries[i][1] / itv)
		{
			q = 0;
			pp = min((queries[i][1] / itv + 1) * itv, n);
			lpmax = 0;
			memset(memo, 0, sizeof(memo));
		}

		while (q < queries[i][2])
		{
			++q;
			memo[0][table[q]] = q;
			if (pp <= q)
			{
				if (memo[1][table[q]] == 0)
					memo[1][table[q]] = q;
				else
					lpmax = max(lpmax, q - memo[1][table[q]]);
			}
		}

		int p = pp;
		int lmax = lpmax;
		while (p > queries[i][1])
		{
			--p;
			if (memo[0][table[p]] > 0)
				lmax = max(lmax, memo[0][table[p]] - p);
		}
		queries[i][3] = lmax;
	}

	sort(queries, queries + m);

	for (int i = 0; i < m; ++i)
		cout << queries[i][3] << '\n';
}