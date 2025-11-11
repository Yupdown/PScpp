#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[1 << 13];

int main()
{
	FASTIO();

	string s;
	cin >> s;
	int n = static_cast<int>(s.size());
	memo[0] = 1;
	if (s[0] != '0')
		memo[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (s[i - 1] != '0')
			memo[i] += memo[i - 1];
		if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
			memo[i] += memo[i - 2];
		memo[i] %= 1000000;
	}
	cout << memo[n];
}