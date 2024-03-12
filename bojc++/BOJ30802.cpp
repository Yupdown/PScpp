#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, c[2][6];
	cin >> n;

	for (int i = 0; i < 6; ++i)
		cin >> c[0][i];

	int t, p;
	cin >> t >> p;

	for (int i = 0; i < 6; ++i)
		c[1][i] = (c[0][i] + t - 1) / t;

	cout << accumulate(c[1], c[1] + 6, 0) << endl << accumulate(c[0], c[0] + 6, 0) / p << ' ' << accumulate(c[0], c[0] + 6, 0) % p;
}