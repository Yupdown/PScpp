#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int input[5000];
int memo[400001][2];

int main()
{
	FASTIO();

	int w, n;
	cin >> w >> n;

	for (int i = 0; i < n; ++i)
		cin >> input[i];

	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int weight = input[i] + input[j];
			if (memo[weight][0] < 0)
			{
				memo[weight][0] = i;
				memo[weight][1] = j;
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int weight = w - (input[i] + input[j]);
			if (weight < 1 || weight > 400000)
				continue;
			if (memo[weight][0] < 0)
				continue;
			if (memo[weight][0] != i && memo[weight][0] != j && memo[weight][1] != i && memo[weight][1] != j)
				flag = true;
		}
	}

	cout << (flag ? "YES" : "NO");
}