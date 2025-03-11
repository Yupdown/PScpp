#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[4][100001];

int main()
{
	FASTIO();

	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i)
	{
		memo[0][i + 1] = memo[0][i] + (s[i] == '(' ? 1 : -1);
		memo[1][n - i - 1] = memo[1][n - i] + (s[n - i - 1] == '(' ? -1 : 1);
		memo[2][i + 1] = min(memo[2][i], memo[0][i + 1]);
		memo[3][n - i - 1] = min(memo[3][n - i], memo[1][n - i - 1]);
	}
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		switch (s[i])
		{
		case '(':
			ret += memo[0][i] - 1 == memo[1][i + 1] && memo[2][i] >= 0 && memo[3][i + 1] >= 0;
			break;
		case ')':
			ret += memo[0][i] + 1 == memo[1][i + 1] && memo[2][i] >= 0 && memo[3][i + 1] >= 0;
			break;
		}
	}
	cout << ret;
}