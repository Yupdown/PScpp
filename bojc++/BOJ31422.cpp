#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int64_t table[200000];
constexpr int64_t MOD = 998'244'353;

int64_t prefix[200001][30];
int64_t prefix_p[200001][30];
int64_t prefix_x[200001][30][3];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < 30; ++j)
		{
			if (table[i] & (1ll << j))
				prefix[i][j] = prefix[i + 1][j] + 1;
			else
				prefix_p[i][j] = prefix_p[i + 1][j] + 1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			if (i == 0)
				prefix_x[i][j][2] = 1;
			prefix_x[i + 1][j][0] = prefix_x[i][j][0] ^ (table[i] >> j & 1);
			prefix_x[i + 1][j][1] = prefix_x[i][j][1] + prefix_x[i + 1][j][0];
			prefix_x[i + 1][j][2] = prefix_x[i][j][2] + 1 - prefix_x[i + 1][j][0];
		}
	}

	int64_t sa = 0;
	int64_t so = 0;
	int64_t sx = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			sa = (sa + (1ll << j) * prefix[i][j]) % MOD;
			so = (so + (1ll << j) * (n - i - prefix_p[i][j])) % MOD;
			sx = (sx + (1ll << j) * prefix_x[i][j][prefix_x[i + 1][j][0] + 1]) % MOD;
		}
	}

	cout << sa << ' ' << so << ' ' << sx;
}