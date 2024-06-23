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
		int x[3];
		cin >> x[0] >> x[1] >> x[2];
		sort(x, x + 3);
		cout << x[2] - x[0] << '\n';
	}
}