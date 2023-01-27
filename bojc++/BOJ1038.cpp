#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

const long long samp = 9876543210ll;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	long long x = 0;
	for (int i = 0; i < n && x >= 0; ++i)
	{
		++x;

		for (long long div = 1; x / div >= 10;)
		{
			long long div10 = div * 10;

			if (x / div10 % 10 <= x / div % 10)
			{
				if (x < samp)
				{
					x = x + div10 - x % div10 + samp % div10;
					div = 1;
				}
				else
				{
					x = -1;
					break;
				}
			}
			else
				div = div10;
		}
	}

	cout << x << '\n';
}