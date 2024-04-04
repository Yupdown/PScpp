#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a + 1 != c)
			cout <<"-1\n";
		else if (a == 0)
			cout << b << "\n";
		else
		{
			int d = (b + c - 1) / c;
			a = a + 1 - ((c - b % c) % c) / 2;
			while (a > 1)
			{
				a = (a + 1) / 2;
				++d;
			}
			cout << d << '\n';
		}
	}
}