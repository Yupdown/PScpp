#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[1 << 20];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long n, m;
		cin >> n >> m;

		if (n > m || n * (n + 1) / 2 < m)
		{
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < n; ++i)
			memo[i] = n - i;
		if (n == m)
			swap(memo[0], memo[n - 1]);
		else
		{
			long long mp = n * (n + 1) / 2;
			for (int i = n - 1; i >= 0; --i)
			{
				int disc = memo[i] - 1;
				if (mp - disc >= m)
					mp -= disc;
				else
				{
					int v = memo[i] - (mp - m);
					swap(memo[i], memo[n - v]);
					swap(memo[i + 1], memo[n - 1]);
					break;
				}
			}
		}
		cout << memo[0] << "\n";
		for (int i = 0; i < n - 1; ++i)
			cout << memo[i] << " " << memo[i + 1] << "\n";
	}
}