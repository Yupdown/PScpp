#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int x, y, c;
	cin >> x >> y >> c;
	int d2 = x * x + y * y;
	if (d2 == 0)
		cout << 0;
	else if (d2 < c * c)
		cout << 2;
	else if (d2 == c * c)
		cout << 1;
	else
		cout << static_cast<int>(ceil(sqrt(d2) / c));
}