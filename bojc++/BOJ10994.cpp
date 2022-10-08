#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int y = 0; y < n * 4 - 3; ++y)
	{
		for (int x = 0; x < n * 4 - 3; ++x)
		{
			int c = (n - 1) * 2;
			cout << (max(abs(x - c), abs(y - c)) % 2 ? ' ' : '*');
		}
		cout << '\n';
	}

	return 0;
}