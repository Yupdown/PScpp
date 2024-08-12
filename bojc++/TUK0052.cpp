#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[1000][1001];
int memo[1000][1000];

int solution(int n, int m, int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return 0;
	if (table[i][j] == '#')
		return 0;
	if (memo[i][j])
		return 0;
	memo[i][j] = 1;
	for (int d = 0; d < 8; ++d)
	{
		int ip = i + "22210001"[d] - '1';
		int jp = j + "21000122"[d] - '1';
		memo[i][j] += solution(n, m, ip, jp);
	}
	return memo[i][j];
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	int k;
	cin >> k;
	int c = 0;
	int smax = 0;
	for (int i = 0; i < n * m; ++i)
	{
		int s = solution(n, m, i / m, i % m);
		if (s > k)
		{
			c++;
			smax = max(smax, s);
		}
	}

	cout << c << ' ' << smax;
}