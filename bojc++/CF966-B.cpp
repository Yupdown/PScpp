#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		memset(table, 0, sizeof(table));
		bool ret = true;
		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			int flag = i == 0;
			if (v > 1)
				flag |= table[v - 1];
			if (v < n)
				flag |= table[v + 1];
			table[v] = 1;
			ret &= flag;
		}
		cout << (ret ? "YES\n" : "NO\n");
	}
}