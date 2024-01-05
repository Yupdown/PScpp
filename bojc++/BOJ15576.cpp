#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

int coef[2][1 << 20];

int scan(int* coef)
{
	static char buffer[1 << 20];
	cin >> buffer;
	int n = strlen(buffer);
	for (int i = 0; i < n; ++i)
	{
		int digit = buffer[n - i - 1] - '0';
		coef[i] = digit;
	}
	return n;
}

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

	int l1 = scan(coef[0]);
	int l2 = scan(coef[1]);

	int n = 1;
	while (n <= l1 + l2)
		n <<= 1;

	vector<cp> f[2];

	for (int i = 0; i < 2; ++i)
	{
		f[i].resize(n);
		for (int j = 0; j < n; ++j)
			f[i][j] = coef[i][j];
	}

	cp w(cos(2 * M_PI / n), sin(2 * M_PI / n));

	fourier_transform(f[0], w);
	fourier_transform(f[1], w);

	for (int i = 0; i < n; ++i)
		f[0][i] *= f[1][i];

	fourier_transform(f[0], cp(1, 0) / w);
	for (int i = 0; i < n; ++i)
		coef[0][i] = round(f[0][i].real() / n);

	stack<int> s;
	int v = 0;
	for (int i = 0; i < n; ++i)
	{
		v += coef[0][i];
		s.push(v % 10);
		v /= 10;
	}
	s.push(v);

	while (!s.empty() && s.top() == 0)
		s.pop();
	
	if (s.empty())
		cout << 0;
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}