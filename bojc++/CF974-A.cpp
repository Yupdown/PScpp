#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[50];

int main()
{
	FASTIO();
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int q = 0, r = 0;
		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			if (v >= k)
				q += v;
			if (v == 0 && q)
			{
				q--;
				r++;
			}
		}
		cout << r << '\n';
	}
}