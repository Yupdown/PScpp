#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int input[100][100];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			input[i][j] = 16'777'216;
	}

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		input[a - 1][b - 1] = min(input[a - 1][b - 1], c);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (j != i && k != i && j != k)
					input[j][k] = min(input[j][k], input[j][i] + input[i][k]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << (input[i][j] >= 16'777'216 ? 0 : input[i][j]) << ' ';
		cout << '\n';
	}
}