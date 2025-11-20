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
		if (table[0] >= 0 && table[n - 1] < 0)
			table[n - 1] = table[0];
		if (table[0] < 0 && table[n - 1] >= 0)
			table[0] = table[n - 1];
		cout << abs(table[0] - table[n - 1]) << "\n";
		for (int i = 0; i < n; ++i)
			cout << (table[i] < 0 ? 0 : table[i]) << " ";
		cout << "\n";
	}
}