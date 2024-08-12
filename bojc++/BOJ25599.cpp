#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long table[1024][1024];

int main()
{
	FASTIO();

	int n;
	long long r;
	cin >> n >> r;
	for (int i = 0; i < n * n; ++i)
		cin >> table[i / n][i % n];

	int k = 0;
	while (k++ < n)
	{
		long long v = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				v += table[i][j];
				table[i][j] = max(table[i][j], table[i + 1][j]);
				table[i][j] = max(table[i][j], table[i][j + 1]);
				table[i][j] = max(table[i][j], table[i + 1][j + 1]);
			}
		}
		if (v >= r)
			break;
	}

	cout << (k <= n ? k : -1);
}