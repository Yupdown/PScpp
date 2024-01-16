#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

vector<cp> coef;
vector<cp> coef_one;

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

	int n, k;
	cin >> n >> k;

	int np = 1 << 20;
	coef.resize(np);

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		coef[x] = 1;
	}

	stack<int> seq;
	for (int exp = k; exp > 1; exp >>= 1)
		seq.push(exp & 1);

	cp w = polar(1.0, 2 * M_PI / np);
	while (!seq.empty())
	{
		fourier_transform(coef, w);
		if (coef_one.empty())
			coef_one = coef;

		for (int i = 0; i < np; ++i)
		{
			coef[i] *= coef[i];
			if (seq.top() > 0)
				coef[i] *= coef_one[i];
		}
		seq.pop();

		fourier_transform(coef, cp(1, 0) / w);
		for (int i = 0; i < np; ++i)
			coef[i] = coef[i].real() / np > 0.5;
	}

	for (int i = 0; i < np; ++i)
	{
		if (coef[i].real() > 0)
			cout << i << ' ';
	}
}