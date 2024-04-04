#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[400][400];
int INF = INT32_MAX / 4;

int main()
{
	FASTIO();

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < v * v; ++i)
		memo[i / v][i % v] = INF;

	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		memo[u - 1][v - 1] = w;
	}

	int vmin = INF;
	for (int k = 0; k < v; ++k) {
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j]);
				if (i == j)
					vmin = min(vmin, memo[i][j]);
			}
		}
	}

	cout << (vmin == INF ? -1 : vmin);
}