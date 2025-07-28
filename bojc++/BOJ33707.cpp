#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1 - i % 2; j < m; j += 2)
		{
			cout << "? " << i + 1 << " " << j + 1 << "\n" << flush;
			int ret;
			if ((cin >> ret) && ret)
				return 0;
		}
	}
}