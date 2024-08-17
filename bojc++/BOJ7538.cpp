#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int k;
	cin >> k;
	for (int t = 0; t < k; ++t)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ret = (a - c & 1) != (b - d & 1);
		cout << "Scenario #" << t + 1 << ":\n" << ret << "\n\n";
	}
}