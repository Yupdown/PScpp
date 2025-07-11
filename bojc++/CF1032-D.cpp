#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[80];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		memset(table, 0, sizeof(table));
		vector<pair<int, int>> ret;

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		for (int i = 0; i < n; ++i)
			cin >> table[i + 40];

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
			{
				if (table[j] > table[j + 1])
				{
					ret.emplace_back(1, j + 1);
					swap(table[j], table[j + 1]);
				}
				if (table[j + 40] > table[j + 41])
				{
					ret.emplace_back(2, j + 1);
					swap(table[j + 40], table[j + 41]);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (table[i] > table[i + 40])
			{
				ret.emplace_back(3, i + 1);
				swap(table[i], table[i + 40]);
			}
		}
		cout << ret.size() << "\n";
		for (const auto& [lhs, rhs] : ret)
			cout << lhs << " " << rhs << "\n";
	}
}