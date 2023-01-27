#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, r = 0;
	cin >> x;
	while (x) {
		r += x & 1;
		x >>= 1;
	}
	cout << r;
}