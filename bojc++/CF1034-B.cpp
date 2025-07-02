#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long n, j, k;
		cin >> n >> j >> k;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		bool flag;
		if (*max_element(table, table + n) == table[j - 1])
			flag = k > 0;
		else
			flag = k > 1;
		cout << (flag ? "YES" : "NO") << "\n";
	}
}