#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(9);

	int z;
	cin >> z;

	while (z-- > 0)
	{
		int x, y, z, r, a, b, c, d;
		cin >> x >> y >> z >> r >> a >> b >> c >> d;
		cout << r * r * 3.14159265358979 << "\n";
	}
}