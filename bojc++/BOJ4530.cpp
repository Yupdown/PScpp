#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int SIZE = 1 << 20;
int prime[SIZE];
int table[SIZE];
int memo[SIZE];

int main()
{
	FASTIO();
	
	prime[1] = 1;
	for (int i = 2; i < SIZE; ++i)
	{
		if (!prime[i])
		{
			for (int j = i * 2; j < SIZE; j += i)
				prime[j] = 1;
		}
	}

	int t;
	cin >> t;
	for (int u = 0; u < t; ++u)
	{
		long long n;
		cin >> n;
		set<int> s;

		memset(table, 0, sizeof(table));
		memset(memo, 0, sizeof(memo));

		while (n--)
		{
			int v;
			cin >> v;
			s.insert(v);
			table[v] = 1;
		}
	
		n = 0;
		while (++n < SIZE)
		{
			if (n * n < SIZE)
			{
				memo[n * n] |= 1 << 1 | table[n] << 8;
				if (n * n * n < SIZE)
				{
					memo[n * n * n] |= 1 << 2 | table[n] << 9;
					if (n * n * n * n < SIZE)
						memo[n * n * n * n] |= 1 << 3 | table[n] << 10;
				}
			}
			long long v = n;
			long long sv = 0;
			long long mv = 1;
			while (v)
			{
				sv += v % 10;
				mv *= v % 10;
				v /= 10;
			}
			memo[n] |= !(n % sv) << 4;
			if (mv)
				memo[n] |= !(n % mv) << 5;

			if (table[n])
			{
				for (int i = sv; i < SIZE; i += sv)
					memo[i] |= i != n << 11;
				for (int i = mv; i < SIZE && mv; i += mv)
					memo[i] |= i != n << 12;
			}
			memo[n] |= !prime[n];
		}

		memo[1] &= ~1792;
		vector<pair<int, int>> ret;
		for (int si : s)
		{
			for (int sj : s)
			{
				if (si != sj && si % sj == 0)
				{
					memo[sj] |= 1 << 6;
					memo[si] |= 1 << 7;
				}
			}
		}
		for (int si : s)
			ret.emplace_back(__builtin_popcount(memo[si]), si);
		sort(ret.begin(), ret.end());

		cout << "DATA SET #" << u + 1 << "\n";
		for (auto [v, i] : ret)
		{
			if (v == ret.back().first)
				cout << i << "\n";
		}
	}

}