#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int get_count(int n, int v)
{
	int c = 0;
	for (int i = 0; i < n; ++i)
		c += min(n, v / (i + 1));
	return c;
}

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;

	int low = 0;
	int high = 1000000000;

	while (high - low > 1)
	{
		int mid = (low + high) / 2;

		if (get_count(n, mid) < k)
			low = mid;
		else
			high = mid;
	}

	cout << high << '\n';
	return 0;
}