#include <bits/stdc++.h>

using namespace std;

vector<int> squares;
int dp[50001] = { 1 };

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i * i <= n; ++i)
		squares.push_back(i * i);

	int c = 0;
	while (!dp[n])
	{
		for (int i = n; i >= 0; --i)
		{
			if (!dp[i])
				continue;
			for (int offset : squares)
			{
				if (i + offset > n)
					break;
				dp[i + offset] = 1;
			}
		}
		++c;
	}

	cout << c;
}