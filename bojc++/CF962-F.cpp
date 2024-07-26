#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long a[200000];
long long b[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
	}
}