#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[100000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		long long ret = 0, c = 0;
		for (int i = 0; i < n; ++i)
		{
			bool flag = false;
			if (i > 0 && i < n - 1)
				flag = (table[i] - table[i - 1]) * (table[i + 1] - table[i]) < 0;
			if (flag)
				c++;
			else if (c > 0)
			{
				ret += (c + 2) * (c + 1) / 2;
				c = 0;
			}
			else if (i > 0)
				ret += table[i] != table[i - 1];
		}
		cout << ret << '\n';
	}
}