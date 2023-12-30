#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int input[100001];
int table_count[200001];
int table_count2[100001];
array<int, 4> query[100000];

int main()
{
	FASTIO();

	while (true)
	{
		int n, m;
		cin >> n;
		if (n == 0)
			break;
		cin >> m;

		for (int i = 1; i <= n; ++i)
			cin >> input[i];

		for (int i = 0; i < m; ++i)
		{
			query[i][0] = i;
			cin >> query[i][1] >> query[i][2];
		}

		int k = static_cast<int>(sqrt(n));
		sort(query, query + m, [=](const array<int, 4>& lhs, const array<int, 4>& rhs) -> bool
			{
				int f1 = lhs[1] / k;
				int f2 = rhs[1] / k;
				return f1 == f2 ? lhs[2] < rhs[2] : f1 < f2;
			}
		);

		int from = 0;
		int to = 0;
		int cnt = 0;

		for (int i = 0; i < m; ++i)
		{
			while (from > query[i][1])
			{
				int v = input[--from] + 100000;
				++table_count[v];
				if (table_count2[table_count[v]]++ == 0)
					++cnt;
			}
			while (to < query[i][2])
			{
				int v = input[++to] + 100000;
				++table_count[v];
				if (table_count2[table_count[v]]++ == 0)
					++cnt;
			}
			while (from < query[i][1])
			{
				if (from > 0)
				{
					int v = input[from] + 100000;
					if (--table_count2[table_count[v]] == 0)
						--cnt;
					--table_count[v];
				}
				++from;
			}
			while (to > query[i][2])
			{
				if (to <= n)
				{
					int v = input[to] + 100000;
					if (--table_count2[table_count[v]] == 0)
						--cnt;
					--table_count[v];
				}
				--to;
			}

			query[i][3] = cnt;
		}

		sort(query, query + m, [](const array<int, 4>& lhs, const array<int, 4>& rhs) -> bool
			{
				return lhs[0] < rhs[0];
			}
		);

		for (int i = 0; i < m; ++i)
			cout << query[i][3] << "\n";

		memset(table_count, 0, sizeof(table_count));
		memset(table_count2, 0, sizeof(table_count2));
	}
}