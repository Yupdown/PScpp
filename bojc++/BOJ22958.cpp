#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, vmax, v, x = 1, base = 2;
	cin >> n;
	cout << "? 1 1 " << n << endl;
	cin >> vmax;
	while (base < n)
	{
		int xp = x + base / 2;
		cout << "? " << xp << " " << base << " " << (n - xp) / base + 1 << endl;
		cin >> v;
		if (v == vmax)
			x = xp;
		base <<= 1;
	}
	if (n > 1)
	{
		cout << "? " << x << " " << n << " 1" << endl;
		cin >> v;
		if (v != vmax)
			x += base / 2;
	}
	cout << "! " << x << endl;
}