#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[4096][4096];
int memo[800][4000];

inline int get_value(int i, int j)
{
	return (table[i][i] + table[j + 1][j + 1] - table[i][j + 1] - table[j + 1][i]) >> 1;
}

void dnc(int i, int l, int r, int kl, int kr)
{
	if (r <= l + 1)
		return;

	int m = (l + r) / 2;
	int vmin = INT_MAX;
	int kmin = 0;
	for (int k = kl; k < kr; ++k)
	{
		int v = memo[i - 1][k] + get_value(k + 1, m);
		if (v < vmin)
		{
			vmin = v;
			kmin = k;
		}
	}

	memo[i][m] = vmin;
	dnc(i, l, m, kl, kmin + 1);
	dnc(i, m, r, kmin, kr);
}

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n * n; ++i)
		cin >> table[i / n][i % n];
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 0; j < n; ++j)
			table[i][j] += table[i + 1][j];
	}
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 0; j < n; ++j)
			table[j][i] += table[j][i + 1];
	}
	for (int i = 0; i < n; ++i)
		memo[0][i] = get_value(0, i);
	for (int i = 1; i < k; ++i)
		dnc(i, 0, n, 0, n);
	
	cout << memo[k - 1][n - 1];
}