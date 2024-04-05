#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n * 2; ++i)
		{
			for (int j = 0; j < n * 2; ++j)
			{
				cout << ((i / 2 + j / 2) % 2 ? '.' : '#');
			}

			cout << '\n';
		}
	}
}