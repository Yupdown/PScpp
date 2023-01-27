#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(3);

	double d, v;
	while (true)
	{
		cin >> d >> v;
		if (!(v > 0 && d > 0))
			break;
		cout << pow(d * d * d - 6.0 * v / 3.14159265358979, 1.0 / 3.0) << "\n";
	}
}