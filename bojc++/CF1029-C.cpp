#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[1 << 18];
int temp[1 << 18];
int memo[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		memset(temp, 0, sizeof(temp));
		for (int i = n - 1; i >= 0; --i)
		{
			int& target = temp[table[i]];
			memo[i] = target > 0 ? target : n;
			target = i;
		}
		int r = 1;
		int curr_target = memo[0];
		int next_target = 0;
		for (int i = 0; i < n; ++i)
		{
			next_target = max(next_target, memo[i]);
			if (i == curr_target)
			{
				r++;
				curr_target = next_target;
			}
		}
		cout << r << "\n";
	}
}