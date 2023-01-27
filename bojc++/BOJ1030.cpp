#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int solution(int s, int n, int k, int x, int y)
{
	int v = (n - k) / 2;
	int xp = x % n;
	int yp = y % n;

	if (!s)
		return 0;

	if (xp >= v && xp < v + k && yp >= v && yp < v + k)
		return 1;

	return solution(s - 1, n, k, x / n, y / n);
}

int main()
{
	FASTIO();

	int s, n, k;
	int r1, r2, c1, c2;

	cin >> s >> n >> k;
	cin >> r1 >> r2 >> c1 >> c2;

	for (int y = r1; y <= r2; ++y)
	{
		for (int x = c1; x <= c2; ++x)
			cout << solution(s, n, k, x, y);
		cout << '\n';
	}
}