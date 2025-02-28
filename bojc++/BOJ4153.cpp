#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int a, b, c;
	while (cin >> a >> b >> c && a)
	{
		sort(&a, &c + 1);
		cout << (c * c == a * a + b * b ? "right\n" : "wrong\n");
	}
}