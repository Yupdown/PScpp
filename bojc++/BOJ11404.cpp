#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100][100];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			table[i][j] = 16'777'216;
	}

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		table[a - 1][b - 1] = min(table[a - 1][b - 1], c);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (j != i && k != i && j != k)
					table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << (table[i][j] >= 16'777'216 ? 0 : table[i][j]) << ' ';
		cout << '\n';
	}
}