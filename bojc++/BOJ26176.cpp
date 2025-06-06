#include <bits/stdc++.h>
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	PRECISION(10);

	long long n;
	cin >> n;

	double x = 0;
	for (double dx = 1e+5; dx > 1e-10; dx /= 2)
	{
		double xp = x + dx;
		long long v = 0;
		for (long long i = 1; i <= static_cast<long long>(xp); ++i)
			v += static_cast<long long>(sqrt(xp * xp - i * i));
		if (v * 4 <= n)
			x = xp;
	}
	cout << x;
}