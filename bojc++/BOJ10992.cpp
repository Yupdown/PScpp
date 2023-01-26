#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n + i; ++j)
			cout << (i + 1 >= n || !(abs(j - n + 1) - i) ? '*' : ' ');
		cout << '\n';
	}

	return 0;
}