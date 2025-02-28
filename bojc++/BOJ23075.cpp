#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, r = 0;
	cin >> n;

	long long m = (n - 1) / 2 - (n - 1) / 3;

	r = m * (m + 1) / 2;
	m -= (n - (n / 3) * 3 + 2) % 3;
	r += m / 2 * (m / 2 + 1);

	if (m % 2)
		r += (m + 1) / 2;

	cout << r << '\n';
}