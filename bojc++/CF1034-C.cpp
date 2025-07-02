#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];
long long mint[200000];
long long maxt[200000];

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
		cout << '1';
		mint[0] = table[0];
		for (int i = 1; i < n; ++i)
			mint[i] = min(table[i], mint[i - 1]);
		maxt[n - 1] = table[n - 1];
		for (int i = n - 2; i >= 0; --i)
			maxt[i] = max(table[i], maxt[i + 1]);
		for (int i = 1; i < n - 1; ++i)
		{
			if (maxt[i] == table[i] || mint[i] == table[i])
				cout << '1';
			else
				cout << '0';
		}
		cout << "1\n";
	}
}