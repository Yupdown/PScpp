#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, k, xi[1000];
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> xi[i];

	sort(xi, xi + n, greater<int>());

	cout << xi[k - 1] << endl;
}