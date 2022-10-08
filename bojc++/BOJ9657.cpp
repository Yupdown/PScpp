#include <bits/stdc++.h>

using namespace std;

int memo[1024];

bool solution(int n, int x)
{
	int step[]{ 1, 3, 4 };
	bool result = false;

	if (memo[x] >= 0)
		return memo[x];

	if (x > n)
		return true;
	if (x == n)
		return false;

	for (int i = 0; i < 3 && !result; ++i)
	{
		if (x + step[i] > n)
			continue;
		if (x + step[i] == n)
		{
			result |= true;
			continue;
		}

		bool sub_result = true;
		for (int j = 0; j < 3; ++j)
			sub_result &= solution(n, x + step[i] + step[j]);
		result |= sub_result;
	}
	
	return memo[x] = result;
}

int main()
{
	int n;
	cin >> n;

	cout << (abs(n % 7 - 1) != 1 ? "SK" : "CY") << endl;
}