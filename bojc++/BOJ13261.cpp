#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long psum[8001];
long long memo[800][8000];

void dnc(int i, int l, int r, int kl, int kr)
{
	if (r <= l + 1)
		return;

	int m = (l + r) / 2;
	long long vmin = LLONG_MAX;
	int kmin = 0;
	for (int k = kl; k < kr; ++k)
	{
		long long v = memo[i - 1][k] + (psum[m + 1] - psum[k + 1]) * (m - k);
		if (v < vmin)
		{
			vmin = v;
			kmin = k;
		}
	}

	memo[i][m] = vmin;
	dnc(i, l, m, kl, kmin + 1);
	dnc(i, m, r, kmin, kr);
}

int main()
{
	FASTIO();

	int l, g;
	cin >> l >> g;

	for (int i = 0; i < l; ++i)
		cin >> psum[i + 1];
	for (int i = 0; i < l; ++i)
		psum[i + 1] += psum[i];
	if (l > g)
	{
		for (int i = 0; i < l; ++i)
			memo[0][i] = psum[i + 1] * (i + 1);
		for (int i = 1; i < g; ++i)
			dnc(i, 0, l, 0, l);
		cout << memo[g - 1][l - 1];
	}
	else
		cout << psum[l];
}