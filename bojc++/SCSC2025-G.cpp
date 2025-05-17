#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

int main()
{
	FASTIO();

	int n;
	string c1, c2;
	cin >> n >> c1 >> c2;

	int xa = 0, ya = 0;
	int xb = 0, yb = 0;
	int diffa = 0, diffb = 0;

	for (int i = 0; i < n * 2 - 1; ++i)
	{
		if (c1[i] == 'R')
			xa++;
		else
			ya++;
		if (c2[i] == 'R')
			xb++;
		else
			yb++;
		if (xa <= xb)
			diffa = max(diffa, min(xb - xa, ya - yb) + 1);
		if (xa >= xb)
			diffb = max(diffb, min(xa - xb, yb - ya) + 1);
	}

	int ret = min(diffa, diffb);
	if (ret == 1 && c1[0] == c2[0] && c1[n * 2 - 1] == c2[n * 2 - 1] && c1[0] == c1[n * 2 - 1])
		ret = 2;

	cout << ret;
}