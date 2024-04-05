#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[200001];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	for (int i = 1; i < 200001; ++i)
	{
		table[i] = table[i - 1];
		for (int j = i; j > 0; j /= 10)
			table[i] += j % 10;
	}

	while (t-- > 0)
	{
		int n;
		cin >> n;
		cout << table[n] << '\n';
	}
}