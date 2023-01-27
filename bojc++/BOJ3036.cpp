#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int gcd(int lhs, int rhs)
{
	return rhs ? gcd(rhs, lhs % rhs) : lhs;
}

int main()
{
	FASTIO();

	int n, r;
	cin >> n >> r;

	for (int i = 0; i < n - 1; ++i)
	{
		int v;
		cin >> v;

		int g = gcd(r, v);
		cout << r / g << "/" << v / g << "\n";
	}
}