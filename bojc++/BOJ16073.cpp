#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[128][128];
int memo[128][128];

void check_and_paint(int i, int j, int di, int dj)
{
	if (table[i + di][j + dj] <= 0)
		return;
	memo[i][j] = 1;
	for (int ip = i - 1; ip <= i + 1; ++ip)
	{
		for (int jp = j - 1; jp <= j + 1; ++jp)
			table[ip][jp]--;
	}
}

bool solution(int n, int m)
{
	for (int k = 0; k < (min(n, m) - 1) / 2; ++k)
	{
		for (int i = 1 + k; i <= n - 1 - k; ++i)
		{
			check_and_paint(i, 1 + k, -1, -1);
			check_and_paint(i, m - 2 - k, -1, 1);
		}
		for (int j = 1 + k; j <= m - 1 - k; ++j)
		{
			check_and_paint(1 + k, j, -1, -1);
			check_and_paint(n - 2 - k, j, 1, -1);
		}
	}
	return all_of(&table[0][0], &table[0][0] + 128 * 128, [](int x) { return x == 0; });
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 2; ++i)
		for (int j = 0; j < m + 2; ++j)
			cin >> table[i][j];
	if (solution(n + 2, m + 2))
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				cout << (memo[i][j] ? 'X' : '.');
			cout << '\n';
		}
	}
	else
		cout << "impossible\n";
}