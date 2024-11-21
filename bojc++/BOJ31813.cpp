#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<long long> table;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	for (long long i = 1; i <= 9; ++i)
	{
		long long v = 0;
		for (int j = 0; j < 17; ++j)
		{
			v = v * 10 + i;
			table.push_back(v);
		}
	}
	sort(table.begin(), table.end());
	while (t--)
	{
		long long n, k;
		cin >> n >> k;

		vector<long long> res;
		while (k != 0)
		{
			auto iter = prev(upper_bound(table.begin(), table.end(), k));
			k -= *iter;
			res.push_back(*iter);
		}

		cout << res.size() << '\n';
		for (const auto& r : res)
			cout << r << ' ';
		cout << '\n';
	}
}