#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int h, n;
	cin >> h >> n;
	vector<bool> memo(h + 1);
	memo[0] = true;
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		int wi;
		cin >> wi;
		for (int j = wi; j <= h; ++j)
			ret = (memo[j] = memo[j] || memo[j - wi]) ? j : ret;
	}
	cout << ret;
}