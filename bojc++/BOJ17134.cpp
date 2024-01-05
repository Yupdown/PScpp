#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

int prime[1 << 20];

vector<cp> coef_odd(1 << 20);
vector<cp> coef_even(1 << 20);
vector<cp> coef_out(1 << 20);

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

	int t;
	cin >> t;

	for (int i = 2; i < 1 << 20; ++i)
		prime[i] = 1;

	for (int i = 2; i < 1 << 20; ++i)
	{
		if (prime[i])
		{
			for (int j = i << 1; j < 1 << 20; j += i)
				prime[j] = 0;
		}
	}

	coef_even[2] = 1;
	for (int i = 2; i < 1 << 20; ++i)
	{
		if (i % 2 && prime[i])
		{
			coef_odd[i >> 1] = 1;
			if (i < 1 << 19)
				coef_even[i] = 1;
		}
	}

	cp w = polar(1.0, 2.0 * M_PI / (1 << 20));

	fourier_transform(coef_odd, w);
	fourier_transform(coef_even, w);

	for (int i = 0; i < 1 << 20; ++i)
		coef_out[i] = coef_odd[i] * coef_even[i];

	fourier_transform(coef_out, cp(1, 0) / w);

	for (int i = 0; i < 1 << 20; ++i)
		coef_out[i] = round(coef_out[i].real() / (1 << 20));

	while (t-- > 0)
	{
		int n;
		cin >> n;
		cout << static_cast<int>(coef_out[(n - 1) >> 1].real()) << '\n';
	}
}