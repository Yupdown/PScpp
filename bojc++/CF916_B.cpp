#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < k; ++i)
			cout << i + 1 << ' ';
		for (int i = n; i > k; --i)
			cout << i << ' ';
		cout << '\n';
	}
}