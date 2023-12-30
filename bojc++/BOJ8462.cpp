#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

int input[100001];
int table_count[1000001];
array<int64, 4> query[100000];

inline int64 get_power(int64 k, int64 s)
{
	return k * k * s;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> input[i];
	
	for (int i = 0; i < m; ++i)
	{
		query[i][0] = i;
		cin >> query[i][1] >> query[i][2];
	}

	int64 k = static_cast<int64>(sqrt(n));
	sort(query, query + m, [=](const array<int64, 4>& lhs, const array<int64, 4>& rhs) -> bool
		{
			int64 f1 = lhs[1] / k;
			int64 f2 = rhs[1] / k;
			return f1 == f2 ? lhs[2] < rhs[2] : f1 < f2;
		}
	);

	int from = 0;
	int to = 0;
	int64 pow = 0;

	for (int i = 0; i < m; ++i)
	{
		while (from < query[i][1])
		{
			if (from >= 0)
			{
				int v = input[from];
				pow += get_power(table_count[v] - 1, v) - get_power(table_count[v], v);
				--table_count[v];
			}
			++from;
		}
		while (from > query[i][1])
		{
			int v = input[--from];
			pow += get_power(table_count[v] + 1, v) - get_power(table_count[v], v);
			++table_count[v];
		}
		while (to < query[i][2])
		{
			int v = input[++to];
			pow += get_power(table_count[v] + 1, v) - get_power(table_count[v], v);
			++table_count[v];
		}
		while (to > query[i][2])
		{
			if (to <= n)
			{
				int v = input[to];
				pow += get_power(table_count[v] - 1, v) - get_power(table_count[v], v);
				--table_count[v];
			}
			--to;
		}

		query[i][3] = pow;
	}

	sort(query, query + m, [](const array<int64, 4>& lhs, const array<int64, 4>& rhs) -> bool
		{
			return lhs[0] < rhs[0];
		}
	);

	for (int i = 0; i < m; ++i)
		cout << query[i][3] << "\n";
}