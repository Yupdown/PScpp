#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long a, b, n;
		cin >> a >> b >> n;
		cout << (a != b && b * n > a ? "2\n" : "1\n");
	}
}