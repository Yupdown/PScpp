#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int dest[10] = { 3, 1, 2, 1, 0, 1, 0, };
		int n;
		cin >> n;
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			dest[v] = max(dest[v] - 1, 0);
			if (ret)
				continue;
			if (accumulate(dest, dest + 10, 0) == 0)
			{
				ret = i + 1;
			}
		}
		if (accumulate(dest, dest + 10, 0) == 0)
			cout << ret << '\n';
		else
			cout << "0\n";
	}
}