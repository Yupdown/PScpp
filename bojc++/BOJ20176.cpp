#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

constexpr int BIAS = 30000;
vector<cp> coef_src(1 << 17);
vector<cp> coef_dest(1 << 17);
int table[1 << 16];

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

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		coef_src[v + BIAS] = 1;
	}

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		table[v + BIAS] = 1;
	}

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		coef_dest[v + BIAS] = 1;
	}

	cp w = polar(1.0, 2.0 * M_PI / (1 << 17));

	fourier_transform(coef_src, w);
	fourier_transform(coef_dest, w);
	for (int i = 0; i < 1 << 17; ++i)
		coef_dest[i] *= coef_src[i];
	fourier_transform(coef_dest, cp(1, 0) / w);
	for (int i = 0; i < 1 << 17; ++i)
		coef_dest[i] = round(coef_dest[i].real() / (1 << 17));

	int res = 0;
	for (int i = 0; i < 1 << 17; i += 2)
		res += table[i >> 1] * static_cast<int>(coef_dest[i].real());
	cout << res;
}