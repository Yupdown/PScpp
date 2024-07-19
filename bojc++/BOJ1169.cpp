#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int ri[100];
int xi[100];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ri[i];

	for (int i = 0; i < n; ++i)
	{
		xi[i] = ri[i];
		for (int j = 0; j < i; ++j)
			xi[i] = max(xi[i], xi[j] + (ri[i] > ri[j] ? ri[j] : ri[i]) * 2);
	}

	for (int i = 0; i < n; ++i)
	{
		int rmax = 0;
		int lmin = 1 << 20;
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			if (ri[i] > ri[j])
				continue;
			if (i < j)
				lmin = min(lmin, xi[j] - ri[j]);
			else
				rmax = max(rmax, xi[j] + ri[j]);
		}
		if (rmax < lmin && rmax < xi[i] + ri[i] && lmin > xi[i] - ri[i])
			cout << i + 1 << ' ';
	}
}