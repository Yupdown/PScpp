#include <bits/stdc++.h>

using namespace std;
int table[3];

int main()
{
	int r = 0;
	for (int i = 0; i < 3; ++i)
	{
		int v;
		cin >> v;
		r += v / 3;
		table[i] = v % 3;
	}
	sort(table, table + 3, greater<int>());
	int rmin = r + 3;
	for (int i = 0; i < 3; ++i)
		rmin = min(rmin, r + i + table[i]);
	cout << rmin;
}