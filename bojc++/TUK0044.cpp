#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int input[1000][1000];
int memo[1001][1001];

int main()
{
	FASTIO();

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m * n; ++i)
		cin >> input[i / n][i % n];

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			memo[i + 1][j + 1] = memo[i + 1][j] + memo[i][j + 1] - memo[i][j] + input[i][j];
	}

	int c;
	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << memo[r2][c2] - memo[r2][c1 - 1] - memo[r1 - 1][c2] + memo[r1 - 1][c1 - 1] << '\n';
	}
}