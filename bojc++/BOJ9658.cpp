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

	if (x >= n)
		return true;

	result |= solution_2(n, x + 1);
	result |= solution_2(n, x + 3);
	result |= solution_2(n, x + 4);

	return memo[x] = result;
}

bool solution_2(int n, int x)
{
	bool result = true;

	if (x >= n)
		return false;

	result &= solution_1(n, x + 1);
	result &= solution_1(n, x + 3);
	result &= solution_1(n, x + 4);

	return result;
}

int main()
{
	int n;
	cin >> n;

	for (int n = 0; n < 100; ++n)
	{
		memset(memo, -1, sizeof(memo));
		cout << (solution_1(n + 1, 0) ? "SK" : "CY") << endl;
	}
}