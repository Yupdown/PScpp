#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int a[200000];
int b[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];

		int r = 0;
		int s = 0;
		priority_queue<int> rep;
		for (int i = 0; i < min(n, k); ++i)
		{
			s += a[i];
			rep.push(b[i]);
			r = max(r, s + rep.top() * (k - i - 1));
		}

		cout << r << '\n';
	}
}