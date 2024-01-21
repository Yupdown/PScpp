#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int adi[300000][2];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> adi[i][0];
		for (int i = 0; i < n; ++i)
			cin >> adi[i][1];
	}
}