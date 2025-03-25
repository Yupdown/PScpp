#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long n, m, k;
		cin >> n >> m >> k;
		
		long long x = m;
		for (long long dx = 1LL << 32; dx > 0; dx >>= 1)
		{
			long long xp = x - dx;
			if (xp < 1)
				continue;
			if ((m - m / (xp + 1)) * n >= k)
				x -= dx;
		}
		cout << x << "\n";
	}
}