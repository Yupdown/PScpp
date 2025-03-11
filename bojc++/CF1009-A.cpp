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
		int l, r, d, u;
		cin >> l >> r >> d >> u;
		if (l == r && d == u && r == d)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}