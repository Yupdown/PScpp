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
		int n;
		cin >> n;

		if (n < 5)
			cout << "-1\n";
		else
		{
			for (int i = 1; i <= n; i += 2)
			{
				if (i != 5)
					cout << i << ' ';
			}
			cout << "5 4";
			for (int i = 2; i <= n; i += 2)
			{
				if (i != 4)
					cout << ' ' << i;
			}
			cout << '\n';
		}
	}
}