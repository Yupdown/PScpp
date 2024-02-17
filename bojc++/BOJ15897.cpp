#include <bits/stdc++.h>

using namespace std;

int64_t func(int64_t a, int64_t b)
{
	if (b > 10000)
	{
		int64_t v = (a + b - 1) / b;
		int64_t t = (a + b - 1) / (v + 1);
		return func(a, t) + (b - t) * v;
	}
	else if (b > 1)
		return func(a, b - 1) + (a + b - 1) / b;
	return a;
}

int main()
{
	int64_t n;
	cin >> n;
	cout << func(n, n);
}