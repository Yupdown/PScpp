#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[10][12];

bool det(int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (table[i][j] == '1')
			{
				return table[i + 1][j] == '1' && table[i][j + 1] == '1' && table[i + 1][j + 1] == '1';
			}
		}
	}
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> table[i];

		cout << (det(n) ? "SQUARE" : "TRIANGLE") << '\n';
	}
}