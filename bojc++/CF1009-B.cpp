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
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		if (n == 1)
			cout << table[0] << "\n";
		else
			cout << accumulate(table, table + n, 0) - n + 1 << "\n";
	}
}