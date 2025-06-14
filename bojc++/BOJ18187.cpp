#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k = 1, r = 1;
	for (int i = 1; i <= n; ++i)
	{
		r += k;
		if (i % 3)
			k++;
	}
	cout << r;
}