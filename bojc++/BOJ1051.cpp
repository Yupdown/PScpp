#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	char c[64][64];

	for (int i = 0; i < n; ++i)
		cin >> c[i];

	int smax = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = j + 1; k < m; ++k)
			{
				if (c[i][j] == c[i][k])
				{
					int d = k - j;

					if (i + d >= n)
						continue;
					if (c[i][j] != c[i + d][j] || c[i][j] != c[i + d][k])
						continue;

					smax = max(smax, (d + 1) * (d + 1));
				}
			}
		}
	}

	cout << (smax > 0 ? smax : 1) << endl;
	return 0;
}