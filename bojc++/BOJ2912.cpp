#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int input[300001];
int table_count[10001];
array<int, 4> query[10000];

int main()
{
	FASTIO();

	int n, c, m;
	cin >> n >> c;

	for (int i = 1; i <= n; ++i)
		cin >> input[i];

	cin >> m;
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

	for (int i = 0; i < m; ++i)
	{
		while (from < query[i][1])
		{
			if (from >= 0)
			{
				int v = input[from];
				--table_count[v];
			}
			++from;
		}
		while (from > query[i][1])
		{
			int v = input[--from];
			++table_count[v];
		}
		while (to < query[i][2])
		{
			int v = input[++to];
			++table_count[v];
		}
		while (to > query[i][2])
		{
			if (to <= n)
			{
				int v = input[to];
				--table_count[v];
			}
			--to;
		}

		int most = -1;
		for (int i = 1; i <= c; ++i)
		{
			if (table_count[i] * 2 > to - from + 1)
				most = i;
		}
		query[i][3] = most;
	}

	sort(query, query + m, [](const array<int, 4>& lhs, const array<int, 4>& rhs) -> bool
		{
			return lhs[0] < rhs[0];
		}
	);

	for (int i = 0; i < m; ++i)
	{
		if (query[i][3] < 0)
			cout << "no";
		else
			cout << "yes " << query[i][3];
		cout << "\n";
	}
}