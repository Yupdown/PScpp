#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

vector<cp> coef;
char table[1 << 20];

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

	int t;
	cin >> t;

	// generate prime numbers to table (0 ~ 2^20)
	for (int i = 2; i * i < 1 << 20; ++i)
	{
		if (!table[i])
		{
			for (int j = i * i; j < 1 << 20; j += i)
				table[j] = 1;
		}
	}

	int np = 1 << 20;
	coef.resize(np);

	// store prime numbers to coef (odd only)
	for (int i = 3; i < 1 << 20; i += 2)
		coef[i >> 1] = !table[i];


	cp w(cos(2 * M_PI / np), sin(2 * M_PI / np));
	fourier_transform(coef, w);

	for (int i = 0; i < np; ++i)
		coef[i] *= coef[i];

	fourier_transform(coef, cp(1, 0) / w);
	for (int i = 0; i < np; ++i)
		coef[i] /= np;

	while (t-- > 0)
	{
		int n;
		cin >> n;
		cout << (n > 4 ? (int)round(coef[(n >> 1) - 1].real()) + 1 >> 1 : 1) << '\n';
	}
}