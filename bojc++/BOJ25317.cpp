#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace __gnu_pbds;
using namespace std;
typedef long long int64;

set<int64> ss;
tree<int64, null_type, less_equal<int64>, rb_tree_tag, tree_order_statistics_node_update> ms;

inline int Sign(long long x)
{
	return x / abs(x);
}

int main()
{
	FASTIO();

	int q;
	cin >> q;

	int xns = 1;
	while (q-- > 0)
	{
		int a;
		long long b, c;
		cin >> a;

		switch (a)
		{
		case 1:
			cin >> b >> c;

			if (b != 0)
			{
				xns *= Sign(b);
				bool ne = Sign(b) * Sign(c) < 0 && c % b;

				if (!(c % b))
					ss.insert(c / b);
				ms.insert((c / b) - ne);
			}
			else if (c != 0)
				xns *= Sign(c);
			else
				xns = 0;
			break;

		case 2:
			cin >> b;

			if (!xns || ss.find(-b) != ss.end())
				cout << '0';
			else
			{
				int bound = ms.order_of_key(-b);
				cout << (((xns > 0) + bound) & 1 ? '+' : '-');
			}

			cout << '\n';
			break;
		}
	}
}