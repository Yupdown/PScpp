#include <bits/stdc++.h>

using namespace std;

bool solution_1(int, int);
bool solution_2(int, int);

int memo[1024];

bool solution_1(int n, int x)
{
	bool result = false;

	if (memo[x] >= 0)
		return memo[x];

	if (x > n)
		return true;
	if (x == n)
		return false;

	for (int i = 1; x + i <= n && !result; i *= 4)
		result |= solution_2(n, x + i);

	return memo[x] = result;
}

bool solution_2(int n, int x)
{
	bool result = true;

	if (x > n)
		return false;
	if (x == n)
		return true;

	for (int i = 1; x + i <= n && result; i *= 4)
		result &= solution_1(n, x + i);

	return result;
}

int main()
{
	int n;
	cin >> n;

	cout << (n % 5 != 0 && n % 5 != 2 ? "SK" : "CY") << endl;

	for (int n = 0; n < 100; ++n)
	{
		memset(memo, -1, sizeof(memo));
		cout << (solution_1(n, 0) ? "SK" : "CY") << endl;
	}
}