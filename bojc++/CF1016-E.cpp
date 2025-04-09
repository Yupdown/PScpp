#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[200000];
int memo[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		int x = 0;
		for (int dx = 1 << 17; dx > 0; dx >>= 1)
		{
			int xp = x + dx;
			int kp = 0;
			memset(memo, 0, 4 * xp);
			int c = 0;
			for (int i = 0; i < n; ++i)
			{
				int num = table[i];
				if (num < xp && memo[num] < kp + 1)
				{
					memo[num]++;
					c++;
				}
				if (c >= (kp + 1) * xp)
					kp++;
			}
			if (kp >= k)
				x += dx;
		}
		cout << x << "\n";
	}
}