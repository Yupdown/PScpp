#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

int main()
{
	FASTIO();

	ll n;
	cin >> n;
	if (n == 1)
		cout << 35 << "\n";
	else
	{
		ll f1 = (n - 3) * (n - 2) + (n - 2) * 2;
		ll f2 = n - 1;
		ll f3 = (n - 3) * (n - 2) / 2 + (n - 2);
		ll f4 = (n - 1) * 2;
		ll f5 = 1;
		ll lmin = f1 * 1 + f2 * 3 + f3 * 6 + f4 * 10 + f5 * 15;
		ll lmax = f1 * 6 + f2 * 11 + f3 * 15 + f4 * 18 + f5 * 20;
		cout << lmin + lmax << "\n";
	}
}