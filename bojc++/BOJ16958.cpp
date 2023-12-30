#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int input[1000][1000];
int point[1000][3];

int main()
{
	FASTIO();

	int n, m, t;
	cin >> n >> t;

	for (int i = 0; i < n; ++i)
		cin >> point[i][0] >> point[i][1] >> point[i][2];

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int dist = abs(point[i][1] - point[j][1]) + abs(point[i][2] - point[j][2]);
			if (point[i][0] && point[j][0])
				dist = min(dist, t);
			input[i][j] = dist;
			input[j][i] = dist;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (j != i && k != i && j != k)
					input[j][k] = min(input[j][k], input[j][i] + input[i][k]);
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << input[a - 1][b - 1] << '\n';
	}
}