#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[200000][20];

int main()
{
	FASTIO();

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
		cin >> table[i][0];

	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < m; ++j)
			table[j][i] = table[table[j][i - 1] - 1][i - 1];
	}

	int q;
	cin >> q;

	while (q-- > 0) {
		int n, x;
		cin >> n >> x;

		for (int i = 0; i < 20; ++i) {
			if (n & 1 << i)
				x = table[x - 1][i];
		}
		cout << x << "\n";
	}
}