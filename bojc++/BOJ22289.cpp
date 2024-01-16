#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef complex<double> cp;

int64_t input[2][1 << 20];
vector<cp> coef[2];

int scan(int64_t* coef)
{
	static char buffer[1 << 20];
	constexpr int64_t base[] = { 1, 10 };
	cin >> buffer;
	int n = strlen(buffer);
	for (int i = 0; i < n; ++i)
	{
		int64_t digit = buffer[n - i - 1] - '0';
		coef[i / 2] += digit * base[i % 2];
	}
	return (n + 1) / 2;
}

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

	int l1 = scan(input[0]);
	int l2 = scan(input[1]);

	int n = 1;
	while (n < l1 + l2)
		n <<= 1;

	for (int i = 0; i < 2; ++i)
	{
		coef[i].resize(n);
		for (int j = 0; j < n; ++j)
			coef[i][j] = input[i][j];
	}

	cp w = polar(1.0, 2.0 * M_PI / n);
	fourier_transform(coef[0], w);
	fourier_transform(coef[1], w);

	for (int i = 0; i < n; ++i)
		coef[0][i] *= coef[1][i];

	fourier_transform(coef[0], cp(1, 0) / w);
	for (int i = 0; i < n; ++i)
		input[0][i] = round(coef[0][i].real() / n);

	stack<int64_t> s;
	int64_t v = 0;
	for (int i = 0; i < n; ++i)
	{
		v += input[0][i];
		s.push(v % 100);
		v /= 100;
	}
	s.push(v);

	while (!s.empty() && s.top() == 0)
		s.pop();

	if (s.empty())
		cout << 0;
	else
	{
		cout << s.top();
		s.pop();
		while (!s.empty())
		{
			cout << setfill('0') << setw(2) << s.top();
			s.pop();
		}
	}
}