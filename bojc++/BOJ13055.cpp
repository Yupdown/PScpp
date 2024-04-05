#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

vector<cp> coef[2];
char input[1 << 20];

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

	cin >> input;
	int n = strlen(input);
	int np = 1;
	while (np < n * 2)
		np <<= 1;

	coef[0].resize(np);
	coef[1].resize(np);
	for (int i = 0; i < n; ++i)
	{
		coef[0][i] = input[i] == 'B';
		coef[1][n - i - 1] = input[i] == 'A';
	}

	cp w = polar(1.0, 2.0 * M_PI / np);
	fourier_transform(coef[0], w);
	fourier_transform(coef[1], w);

	for (int i = 0; i < np; ++i)
		coef[0][i] *= coef[1][i];

	fourier_transform(coef[0], cp(1, 0) / w);
	for (int i = 0; i < np; ++i)
		coef[0][i] = round(coef[0][i].real() / np);

	for (int i = 0; i < n - 1; ++i)
		cout << static_cast<int>(coef[0][n - i - 2].real()) << '\n';
}