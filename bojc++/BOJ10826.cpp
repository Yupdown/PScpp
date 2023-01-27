#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, v[2] = { 0, 1 };
	cin >> n;

	while (n-- > 0)
	{
		long long temp = v[0] + v[1];
		v[0] = v[1];
		v[1] = temp;
	}

	cout << v[0];
}