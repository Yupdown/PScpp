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
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		long long ret = 0, maxv = table[0];
		for (int i = 0; i < n; ++i)
		{
			ret += max(table[i], table[(i + 1) % n]);
			maxv = max(maxv, table[i]);
		}
		cout << ret - maxv << "\n";
	}
}