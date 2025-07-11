#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char s[1 << 20];
// memo[0][i]: the cost to transform every element of [0, i] of s into 'A'
// memo[1][i]: the cost to transform every element of [0, i] of s into 'B'
int memo[2][1 << 20];

int main()
{
	FASTIO();

	int n;
	cin >> n >> s;
	memo[0][0] = s[0] != 'A';
	memo[1][0] = s[0] != 'B';
	for (int i = 1; i < n; ++i)
	{
		memo[0][i] = memo[0][i - 1] + (s[i] == 'B');
		memo[1][i] = memo[1][i - 1] + (s[i] == 'A');
		tie(memo[0][i], memo[1][i]) = make_tuple(min(memo[0][i], memo[1][i] + 1), min(memo[0][i] + 1, memo[1][i]));
	}
	cout << memo[0][n - 1];
}