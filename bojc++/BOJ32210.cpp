#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> pli[100];
tuple<int, int, int, int> abi[200000];
int memo[1 << 20];

int main()
{
	FASTIO();

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> pli[i].first >> pli[i].second;
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		cin >> a >> b;
		abi[i] = make_tuple(i, a, b, 0);
	}

	sort(pli, pli + n, [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; });
	sort(abi, abi + q, [](const auto& lhs, const auto& rhs) { return get<2>(lhs) < get<2>(rhs); });

	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		while (j < q && get<2>(abi[j]) < pli[i].second)
		{
			get<3>(abi[j]) = memo[get<1>(abi[j])] >= get<2>(abi[j]);
			++j;
		}
		for (int k = 1000000; k > pli[i].first; --k)
		{
			if (memo[k - pli[i].first] > 0)
				memo[k] = max(memo[k], memo[k - pli[i].first] + pli[i].second);
		}
		memo[pli[i].first] = max(memo[pli[i].first], pli[i].second);
	}
	while (j < q)
	{
		get<3>(abi[j]) = memo[get<1>(abi[j])] >= get<2>(abi[j]);
		++j;
	}

	sort(abi, abi + q);
	for (int i = 0; i < q; ++i)
		cout << (get<3>(abi[i]) ? "YES\n" : "NO\n");
}