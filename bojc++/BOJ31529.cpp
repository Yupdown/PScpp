#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	if (x > y)
		cout << -1;
	else
	{
		int w = (x * 2 - y) * 506;
		if (w < 0)
			cout << -1;
		else
			cout << w;
	}
}