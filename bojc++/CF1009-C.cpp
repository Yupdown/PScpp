#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long x;
		cin >> x;
		long long z = 1;
		while (z <= x)
			z <<= 1;
		long long xy = z - 1;
		long long y = x ^ xy;
		z >>= 1;
		long long r = -1;
		if (xy != x)
		{
			while (z > 0)
			{
				if (~y & z && (y | z) < x)
				{
					r = y | z;
					break;
				}
				z >>= 1;
			}
		}

		cout << r << "\n";
	}
}