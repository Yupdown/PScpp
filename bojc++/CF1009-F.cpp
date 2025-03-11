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
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		int ret = 0;
		while (r1 - l1 > 0 && r2 - l2 > 0)
		{
			if (l1 & 1)
			{
				ret += r2 - l2;
				l1 += 1;
			}
			if (r1 & 1)
			{
				ret += r2 - l2;
				r1 -= 1;
			}
			if (l2 & 1)
			{
				ret += r1 - l1;
				l2 += 1;
			}
			if (r2 & 1)
			{
				ret += r1 - l1;
				r2 -= 1;
			}
			l1 >>= 1;
			r1 >>= 1;
			l2 >>= 1;
			r2 >>= 1;
		}
		cout << ret << "\n";
	}
}