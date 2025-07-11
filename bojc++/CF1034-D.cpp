#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char table[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k >> table;
		bool flag = false;
		if (count(table, table + n, '1') <= k)
			flag = true;
		else if (k > n / 2)
			flag = true;
		cout << (flag ? "Alice\n" : "Bob\n");
	}
}