#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[1000][1001];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> table[i];

		for (int i = 0; i < n / k; ++i)
		{
			for (int j = 0; j < n / k; ++j)
				cout << table[i * k][j * k];
			cout << '\n';
		}
	}
}