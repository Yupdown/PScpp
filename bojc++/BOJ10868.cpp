#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100000][18];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> table[i][0];

	for (int i = 1; i < 18; ++i) {
		for (int j = 0; j < n; ++j) {
			int delta = 1 << (i - 1);
			if (j + delta < n)
				table[j][i] = min(table[j][i - 1], table[j + delta][i - 1]);
		}
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		int x = a - 1;
		int r = table[x][0];

		for (int j = 0; j < 18; ++j) {
			if (b - a + 1 & 1 << j) {
				r = min(r, table[x][j]);
				x += 1 << j;
			}
		}

		cout << r << "\n";
	}
}