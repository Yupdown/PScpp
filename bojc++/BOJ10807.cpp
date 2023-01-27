#include <bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
	int n, v;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> v;
	cout << count(a, a + n, v) << endl;
}