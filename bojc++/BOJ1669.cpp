#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int n = sqrt(y - x);
	if (!n)
		cout << 0 << endl;
	else
		cout << (n * 2 - 1 + (y - x - n * (n - 1) - 1) / n) << endl;
}