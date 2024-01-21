#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

vector<cp> coef[2][100];

void fourier_transform(vector<cp>& f, cp w)
{
	int n = f.size();
	int half = n >> 1;
	vector<cp> even(half), odd(half);

	for (int i = 0; i < half; ++i)
	{
		even[i] = f[i << 1];
		odd[i] = f[i << 1 | 1];
	}

	if (half > 1)
	{
		fourier_transform(even, w * w);
		fourier_transform(odd, w * w);
	}

	cp wp(1, 0);
	for (int i = 0; i < half; ++i)
	{
		f[i] = even[i] + wp * odd[i];
		f[i + half] = even[i] - wp * odd[i];
		wp *= w;
	}
}

int main()
{
	FASTIO();

	int n, l, m;
	int64_t w;
	cin >> n >> l >> m >> w;

	int np = 1;
	while (np < n + l)
		np <<= 1;

	for (int i = 0; i < m * 2; ++i)
		coef[i / m][i % m].resize(np);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int v;
			cin >> v;
			coef[0][i][j] = v;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < l; ++j)
		{
			int v;
			cin >> v;
			coef[1][i][l - j - 1] = v;
		}
	}

	cp w1 = polar(1.0, 2 * M_PI / np);
	for (int i = 0; i < m * 2; ++i)
		fourier_transform(coef[i / m][i % m], w1);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < np; ++j)
			coef[0][i][j] *= coef[1][i][j];
	}

	for (int i = 0; i < m; ++i)
		fourier_transform(coef[0][i], cp(1, 0) / w1);

	int res = 0;
	for (int i = l - 1; i < n; ++i)
	{
		int64_t wp = 0;
		for (int j = 0; j < m; ++j)
			wp += static_cast<int64_t>(round(coef[0][j][i].real() / np));
		res += wp > w;
	}

	cout << res;
}