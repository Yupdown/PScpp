#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

vector<cp> coef(1 << 19);

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

	int n, m;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		coef[v] = 1;
	}

	cp w = polar(1.0, 2.0 * M_PI / (1 << 19));
	fourier_transform(coef, w);
	for (int i = 0; i < coef.size(); ++i)
		coef[i] = coef[i] * coef[i] + coef[i];
	fourier_transform(coef, cp(1, 0) / w);
	for (int i = 0; i < coef.size(); ++i)
		coef[i] = round(coef[i].real() / coef.size());

	int res = 0;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int v;
		cin >> v;
		res += coef[v].real() > 0;
	}

	cout << res;
}