#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

int table[2000][2000];
pair<int, int> query[2000];
tuple<pair<int, int>, int, int> memo[2000];
constexpr ll MOD = 998'244'353;

int main()
{
	FASTIO();

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n * n; ++i)
		cin >> table[i / n][i % n];
	for (int i = 0; i < q; ++i)
		cin >> query[i].first >> query[i].second;

	for (int i = 0; i < n; ++i)
		memo[i] = make_tuple(make_pair(0, 0), i, i);

	for (int i = 0; i < q; ++i)
	{
		sort(memo, memo + n, [](const auto& lhs, const auto& rhs) { return get<2>(lhs) < get<2>(rhs); });
		// If the sort is not stable
		if (query[i].first == 1)
		{
			for (int j = 0; j < n; ++j)
				get<0>(memo[j]) = make_pair(table[j][query[i].second - 1], 0);
		}
		// If the sort is stable
		else
		{
			for (int j = 0; j < n; ++j)
				get<0>(memo[j]) = make_pair(table[j][query[i].second - 1], get<1>(memo[j]));
		}
		sort(memo, memo + n, [](const auto& lhs, const auto& rhs) { return get<0>(lhs) < get<0>(rhs); });
		get<1>(memo[0]) = 0;
		for (int j = 1; j < n; ++j)
			get<1>(memo[j]) = get<1>(memo[j - 1]) + (get<0>(memo[j - 1]) < get<0>(memo[j]));
	}

	ll ret = 1, addv = 1;
	for (int i = 1, c = 1; i < n; ++i)
	{
		if (get<1>(memo[i - 1]) == get<1>(memo[i]))
			addv = (addv * ++c) % MOD;
		else
		{
			ret = (ret * addv) % MOD;
			addv = 1;
			c = 1;
		}
	}
	ret = (ret * addv) % MOD;
	cout << ret;
}