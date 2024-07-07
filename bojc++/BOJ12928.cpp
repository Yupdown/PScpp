#include <bits/stdc++.h>

using namespace std;

int memo[64][2048];

bool solution(int n, int s)
{
	if (s < 0)
		return false;
	if (memo[n][s])
		return false;
	if (n == 0)
		return s == 0;
	for (int i = 1; i <= n; ++i)
	{
		if (solution(n - i, s - (i * (i + 1))))
			return true;
	}
	memo[n][s] = 1;
	return false;
}

int main()
{
	int n, s;
	cin >> n >> s;

	bool flag = false;
	for (int i = 1; i < n; ++i)
		flag |= solution(n - i - 1, s * 2 - (i * (i - 1)));

	cout << flag;
}