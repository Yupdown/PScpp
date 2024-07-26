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
		int n;
		cin >> n;
		cout << n / 4 + (n % 4) / 2 << '\n';
	}
}