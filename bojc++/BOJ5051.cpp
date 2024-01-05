#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

vector<cp> coef;

void fourier_transform(vector<cp>& f, cp w)
{
	int n = f.size();
	int half = n >> 1;
	vector<cp> even(half), odd(half);

	for (int i = 0; i < half; ++i)
	{
		even[i] = f[i * 2];
		odd[i] = f[i * 2 + 1];
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

	int64_t n;
	cin >> n;

	int64_t np = 1;
	while (np < n << 1)
		np <<= 1;
	coef.resize(np);

	for (int64_t i = 1; i < n; ++i)
	{
		int64_t v = i * i % n;
		coef[v] = coef[v].real() + 1;
	}

	cp w = polar(1.0, 2.0 * M_PI / np);
	fourier_transform(coef, w);
	for (int i = 0; i < np; ++i)
		coef[i] *= coef[i];
	fourier_transform(coef, cp(1, 0) / w);
	for (int i = 0; i < np; ++i)
		coef[i] = round(coef[i].real() / np);
	for (int64_t i = 1; i < n; ++i)
	{
		int64_t v = i * i * 2 % n;
		coef[v] = coef[v].real() + 1;
	}

	int64_t s = 0;
	for (int64_t i = 1; i < n; ++i)
	{
		int64_t v = i * i % n;
		s += static_cast<int64_t>(coef[v].real() + coef[v + n].real());
	}
	cout << (s >> 1);
}