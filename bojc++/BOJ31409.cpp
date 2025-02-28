#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (table[i] == i + 1)
		{
			table[i]++;
			cnt++;
		}
	}

	if (table[n - 1] > n)
		table[n - 1] = 1;

	cout << cnt << '\n';
	for (int i = 0; i < n; ++i)
		cout << table[i] << ' ';
}