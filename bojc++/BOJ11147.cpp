#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[200][200];
int order[200];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> order[i];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				cin >> table[i][j];
		}
		replace(table[0], table[0] + 40000, -1, 1 << 22);
		for (int m = 0; m < n; ++m)
		{
			for (int l = 0; l < n; ++l)
			{
				for (int r = 0; r < n; ++r)
					table[l][r] = min(table[l][r], table[l][m] + table[m][r]);
			}
		}
		long long r = 0;
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			long long v = table[order[i]][order[(i + 1) % n]];
			r += v;
			flag &= v < 1 << 22;
				
		}
		if (flag)
			cout << r << "\n";
		else
			cout << "impossible\n";
	}
}