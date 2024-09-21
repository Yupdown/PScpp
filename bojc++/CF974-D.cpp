#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int psuml[1 << 17];
int psumr[1 << 17];

int main()
{
	FASTIO();
	int t;
	cin >> t;

	while (t--)
	{
		int n, d, k;
		cin >> n >> d >> k;
		memset(psuml, 0, sizeof(psuml));
		memset(psumr, 0, sizeof(psumr));
		for (int i = 0; i < k; ++i)
		{
			int l, r;
			cin >> l >> r;
			psuml[l - 1]++;
			psumr[r]++;
		}
		int v = 0;
		for (int i = 0; i < d; ++i)
			v += psuml[i];
		int vmin = v;
		int imin = 0;
		int vmax = v;
		int imax = 0;
		for (int i = d; i <= n; ++i)
		{
			v -= psumr[i - d];
			if (v < vmin)
			{
				vmin = v;
				imin = i - d;
			}
			if (v > vmax)
			{
				vmax = v;
				imax = i - d;
			}
			v += psuml[i];
		}
		cout << imax + 1 << ' ' << imin + 1 << '\n';
	}
}