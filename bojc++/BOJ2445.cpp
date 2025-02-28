#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n * 2 - 1; ++i)
	{
		for (int j = 0; j < n * 2; ++j)
			cout << (abs(j - n + j / n) > abs(i - n + 1) ? '*' : ' ');
		cout << '\n';
	}

	return 0;
}