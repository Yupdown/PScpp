#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

int main()
{
	ll k;
	cin >> k;

	ll lhsmin = INT_MAX;
	ll rhsmin = INT_MAX;
	for (ll lhs = 1; lhs <= k; ++lhs)
	{
		if (k % lhs)
			continue;
		ll rhs = k / lhs;
		if (rhs <= lhs + 1)
		{
			if (lhs + rhs < lhsmin + rhsmin)
			{
				lhsmin = lhs;
				rhsmin = rhs;
			}
		}
	}

	cout << lhsmin + rhsmin << "\n";
	ll delta = lhsmin - rhsmin + 1;
	ll c = lhsmin + 1;
	for (int i = 0; i < lhsmin; ++i)
	{
		cout << i + 1 << " " << i + 2 << "\n";
		if (i >= delta)
			cout << i + 1 << " " << ++c << "\n";
	}
}