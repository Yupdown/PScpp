#include <bits/stdc++.h>

using namespace std;
int memo[2][1 << 18];

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	memo[0][n] = 1;
	memo[1][n] = 1;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		for (int j : { i + 1, i - 1, i * 2 })
		{
			if (j < 0 || j > 1 << 18)
				continue;
			if (memo[0][j] > 0 && memo[0][j] < memo[0][i] + 1)
				continue;
			if (memo[0][j] == memo[0][i] + 1)
			{
				memo[1][j] += memo[1][i];
				continue;
			}
			memo[0][j] = memo[0][i] + 1;
			memo[1][j] = memo[1][i];
			q.push(j);
		}
	}
	cout << memo[0][k] - 1 << "\n" << memo[1][k];
}