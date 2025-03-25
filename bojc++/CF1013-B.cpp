#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long n, x;
		cin >> n >> x;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		sort(table, table + n);
		long long ret = 0;
		long long li = n;
		for (int i = n - 1; i >= 0; --i)
		{
			if ((li - i) * table[i] >= x)
			{
				ret++;
				li = i;
			}
		}
		cout << ret << '\n';
	}
}