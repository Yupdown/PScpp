#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int c = 0;
	for (int d = 5; d <= n; d *= 5)
		c += n / d;

	cout << c;
}