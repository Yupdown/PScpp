#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int q;
	cin >> q;

	while (q-- > 0)
	{
		int ta, tb, va, vb;
		cin >> ta >> tb >> va >> vb;

		int t = tb * vb;
		int tp = ta * va - t;
		if (tp > 0)
		{
			va -= t / ta;
			int a = (tp - 1) % ta + 1;
			int b = ta;

			while (va > 0)
			{
				++t;
				if (--a <= 0)
				{
					--va;
					a = ta;
				}
				if (--b <= 0)
				{
					--va;
					b = ta;
				}
			}
		}

		cout << t << '\n';
	}
}