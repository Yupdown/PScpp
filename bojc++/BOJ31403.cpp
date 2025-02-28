#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int a, b, c;
	cin >> a >> b >> c;

	cout << a + b - c << endl;

	int n = 1;
	while (n <= b)
		n *= 10;

	cout << a * n + b - c;
}