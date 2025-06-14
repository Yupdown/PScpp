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
		int r = n * 2 - 1;
		cout << r << "\n";
		cout << 1 << " " << 1 << " " << n << "\n";
		for (int i = 1; i < n; ++i)
		{
			cout << i + 1 << " " << 1 << " " << i << "\n";
			cout << i + 1 << " " << i + 1 << " " << n << "\n";
		}
	}
}