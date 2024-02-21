#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[200000];
long long memo[200000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i];


	memo[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (table[i - 1] < table[i])
			memo[i] = memo[i - 1] + 1;
		else
			memo[i] = 1;
	}

	cout << accumulate(memo, memo + n, 0ll);
}