#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int a[200000];
int table[26];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			string s;
			cin >> s;

			if (s.size() != n)
				cout << "NO\n";
			else
			{
				fill(table, table + 26, INT_MAX);
				map<int, int> itable;
				bool flag = true;
				for (int j = 0; j < s.size() && flag; ++j)
				{
					if (table[s[j] - 'a'] == INT_MAX)
						table[s[j] - 'a'] = a[j];
					else
						flag &= table[s[j] - 'a'] == a[j];

					if (itable.find(a[j]) == itable.end())
						itable.emplace(a[j], s[j] - 'a');
					else
						flag &= itable[a[j]] == s[j] - 'a';

				}
				cout << (flag ? "YES\n" : "NO\n");
			}
		}
	}
}