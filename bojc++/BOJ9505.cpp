#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int NMAX = 1000;
constexpr int MMAX = 1000;

int mapping[26];
int table[NMAX][MMAX];
long long memo[NMAX][MMAX];

int main()
{
	FASTIO();
	
	int t;
	cin >> t;
	while (t--)
	{
		int k, n, m;
		cin >> k >> m >> n;

		for (int i = 0; i < k; ++i)
		{
			char c;
			int v;
			cin >> c >> v;
			mapping[c - 'A'] = v;
		}
		int si, sj;
		for (int i = 0; i < n * m; ++i)
		{
			char c;
			cin >> c;
			if (c == 'E')
				tie(si, sj) = make_pair(i / m, i % m);
			table[i / m][i % m] = mapping[c - 'A'];
		}

		priority_queue<tuple<long long, int, int>> pq;
		pq.emplace(0, si, sj);
		memset(memo, 0x10, sizeof(memo));
		memo[si][sj] = 0;

		while (!pq.empty())
		{
			auto [v, i, j] = pq.top();
			pq.pop();

			v = -v;
			if (memo[i][j] < v)
				continue;

			for (int d = 0; d < 4; ++d)
			{
				int ip = i + "1120"[d] - '1';
				int jp = j + "2011"[d] - '1';

				if (ip < 0 || ip >= n || jp < 0 || jp >= m)
					continue;
				long long vp = memo[i][j] + table[ip][jp];
				if (vp >= memo[ip][jp])
					continue;
				memo[ip][jp] = vp;
				pq.emplace(-vp, ip, jp);
			}
		}

		long long vmin = LLONG_MAX;
		for (int i = 0; i < n; ++i)
		{
			vmin = min(vmin, memo[i][0]);
			vmin = min(vmin, memo[i][m - 1]);
		}
		for (int i = 0; i < m; ++i)
		{
			vmin = min(vmin, memo[0][i]);
			vmin = min(vmin, memo[n - 1][i]);
		}
		cout << vmin << "\n";
	}
}