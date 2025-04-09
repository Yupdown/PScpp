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
		long long k;
		cin >> k;
		cout << (k & 1 ? "YES" : "NO") << "\n";
	}
}