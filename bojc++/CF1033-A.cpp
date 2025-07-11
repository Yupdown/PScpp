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
		long long l1, b1, l2, b2, l3, b3;
		cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

		bool c = false;
		if (l1 == l2 && l2 == l3)
		{
			if (b1 + b2 + b3 == l1)
				c |= true;
		}
		if (2 * l1 == l1 + l2 + l3)
		{
			if (b2 == b3 && b1 + b2 == l1)
				c |= true;
		}
		if (2 * l2 == l1 + l2 + l3)
		{
			if (b1 == b3 && b2 + b1 == l2)
				c |= true;
		}
		if (2 * l3 == l1 + l2 + l3)
		{
			if (b1 == b2 && b3 + b1 == l3)
				c |= true;
		}

		swap(l1, b1);
		swap(l2, b2);
		swap(l3, b3);

		if (l1 == l2 && l2 == l3)
		{
			if (b1 + b2 + b3 == l1)
				c |= true;
		}
		if (2 * l1 == l1 + l2 + l3)
		{
			if (b2 == b3 && b1 + b2 == l1)
				c |= true;
		}
		if (2 * l2 == l1 + l2 + l3)
		{
			if (b1 == b3 && b2 + b1 == l2)
				c |= true;
		}
		if (2 * l3 == l1 + l2 + l3)
		{
			if (b1 == b2 && b3 + b1 == l3)
				c |= true;
		}

		cout << (c ? "YES\n" : "NO\n");
	}
}