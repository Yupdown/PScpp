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
		int a, b, c;
		cin >> a >> b >> c;

		if (a < b && b < c)
			cout << "STAIR" << '\n';
		else if (a < b && b > c)
			cout << "PEAK" << '\n';
		else
			cout << "NONE" << '\n';
	}
}