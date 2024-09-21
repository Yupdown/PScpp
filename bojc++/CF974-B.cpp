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
		int n, k;
		cin >> n >> k;
		cout << ((n & 1 ? (k + 1) / 2 : k / 2) & 1 ? "NO" : "YES") << '\n';
	}
}