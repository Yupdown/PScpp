#include <bits/stdc++.h>

using namespace std;
int table[50];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	sort(table, table + n);
	long long result = 0;
	for (int l = 0; l < n; ++l)
	{
		for (int r = l + 2; r < n; ++r)
		{
			int m = max<int>(distance(table, upper_bound(table + l, table + r, table[r] - table[l])), l + 1);
			result += (1LL << r - m) - 1;
		}
	}
	cout << result;
}