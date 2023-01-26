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
		for (int j = 0; j < (i % 2 ? n * 2 : n * 2 - 1); ++j)
			cout << ((i + j) % 2 ? ' ' : '*');
		cout << endl;
	}

	return 0;
}