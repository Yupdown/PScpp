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
		long long x, k;
		cin >> x >> k;
		bool flag = true;
		if (k > 1)
			flag = k == 2 && x == 1;
		else if (x == 1)
			flag = false;
		else
		{
			for (long long y = 2; y * y <= x; ++y)
				flag &= x % y > 0;
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}
}