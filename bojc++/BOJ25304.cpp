#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int x, n;
	cin >> x >> n;

	while (n-- > 0)
	{
		int a, b;
		cin >> a >> b;
		x -= a * b;
	}

	cout << (x ? "No" : "Yes") << "\n";
}