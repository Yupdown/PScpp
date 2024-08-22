#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	int b = n << 20;
	cout << (t + n - 1) / n << '\n';
	for (int i = 0; i < (t - 1) / n; ++i)
		cout << char((b - 1 - i) % n + 97) << ' ';
	cout << char((b - 1 - (t - 1) / n + t) % n + 97);
}