#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long memo[100000][5];

int main()
{
	FASTIO();
	int n;
	string s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		memo[i][0] = 1;
	for (int c = 0; c < 4; ++c)
	{
		char ch = "DKSH"[c];
		memo[0][c + 1] = memo[0][c] * (s[0] == ch);
		for (int i = 1; i < n; ++i)
			memo[i][c + 1] = memo[i - 1][c + 1] + memo[i][c] * (s[i] == ch);
	}
	cout << memo[n - 1][4];
}