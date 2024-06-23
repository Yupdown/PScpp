#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> table[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> table[i].first;
		for (int i = 0; i < n; ++i)
			cin >> table[i].second;

		sort(table, table + n, [](const auto& lhs, const auto& rhs) {return lhs.first + lhs.second > rhs.first + rhs.second; });

		long long r = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i & 1)
				r -= table[i].second - 1;
			else
				r += table[i].first - 1;
		}

		cout << r << '\n';
	}
}