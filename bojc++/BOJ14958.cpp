#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

vector<cp> coef[6];
char input[2][1 << 17];

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

	int n, m;
	cin >> n >> m;
	cin >> input[0] >> input[1];

	int np = 1;
	while (np < n << 1)
		np <<= 1;

	for	(int i = 0; i < 6; ++i)
		coef[i].resize(np);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			char c = "RPS"[j];
			if (input[0][i] == c)
				coef[j][i] = 1;
			if (i < m && input[1][i] == c)
				coef[j + 3][m - i - 1] = 1;
		}
	}

	cp w = polar(1.0, 2.0 * M_PI / np);
	for (int i = 0; i < 6; ++i)
		fourier_transform(coef[i], w);

	for (int i = 0; i < np; ++i)
	{
		for (int j = 0; j < 3; ++j)
			coef[j][i] *= coef[(j + 1) % 3 + 3][i];
	}

	for (int i = 0; i < 3; ++i)
	{
		fourier_transform(coef[i], cp(1, 0) / w);
		for (int j = 0; j < np; ++j)
			coef[i][j] = round(coef[i][j].real() / np);
	}

	int vmax = 0;
	for (int i = m - 1; i < np; ++i)
	{
		int v = 0;
		for (int j = 0; j < 3; ++j)
			v += coef[j][i].real();
		vmax = max(vmax, v);
	}

	cout << vmax;
}