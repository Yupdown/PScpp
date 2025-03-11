#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long xi[200000];
long long ri[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> xi[i];
		for (int i = 0; i < n; ++i)
			cin >> ri[i];
		map<long long, long long> hm;
		for (int i = 0; i < n; ++i)
		{
			long long x = xi[i];
			long long r = ri[i];
			for (int xp = x - r; xp <= x + r; ++xp)
			{
				long long dx = xp - x;
				long long y = sqrt(r * r - dx * dx);
				hm[xp] = max(hm[xp], y * 2 + 1);
			}
		}
		long long r = 0;
		for (const auto& [k, p] : hm)
			r += p;
		cout << r << "\n";
	}
}