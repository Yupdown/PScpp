#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == b)
			cout << c;
		else if (b == c)
			cout << a;
		else
			cout << b;
		cout << '\n';
	}
}