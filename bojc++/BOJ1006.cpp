#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int u[10000][2];
int m[10000][3];

int solution(int n, int w, int c)
{
	if (n == 1)
		return 1 + (u[0][0] + u[0][1] > w);

	m[0][0] = c == 0 && u[0][0] + u[0][1] > w ? 2 : c != 3 ? 1 : 0;
	m[0][1] = !(c & 1);
	m[0][2] = !(c & 2);

	for (int i = 1; i < n; ++i)
	{
		int x0 = 1 + (u[i - 1][0] + u[i][0] > w);
		int x1 = 1 + (u[i - 1][1] + u[i][1] > w);
		int y0 = 1 + (u[i][0] + u[i][1] > w);

		m[i][0] = (i > 1 ? m[i - 2][0] : 0) + x0 + x1;
		m[i][0] = min(min(m[i][0], m[i - 1][0] + y0), min(m[i - 1][1] + x1 + 1, m[i - 1][2] + x0 + 1));
		m[i][1] = min(m[i - 1][0] + 1, m[i - 1][2] + x0);
		m[i][2] = min(m[i - 1][0] + 1, m[i - 1][1] + x1);
	}

	switch (c)
	{
	case 0:
		return m[n - 1][0];
	case 1:
		return m[n - 1][2];
	case 2:
		return m[n - 1][1];
	case 3:
		return m[n - 2][0];
	default:
		return 0;
	}
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, w;
		cin >> n >> w;

		for (int i = 0; i < n * 2; ++i)
			cin >> u[i % n][i / n];

		int t0 = u[0][0] + u[n - 1][0] <= w;
		int t1 = u[0][1] + u[n - 1][1] <= w;

		int r = solution(n, w, 0);
		if (t0)
			r = min(r, solution(n, w, 1) + 1);
		if (t1)
			r = min(r, solution(n, w, 2) + 1);
		if (t0 && t1)
			r = min(r, solution(n, w, 3) + 2);

		cout << r << endl;
	}

	return 0;
}