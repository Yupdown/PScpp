#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();
	
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int c = 0;
		for (int d = 5; d <= n; d *= 5)
			c += n / d;

		cout << c << '\n';
	}
}