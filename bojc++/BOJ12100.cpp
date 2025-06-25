#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
bool flag;
alignas(64) int table[11][20][20];

int solution_merge(int n, int* from, int* to, int offset)
{
	int ret = 0, j = 0;
	for (int i = 0; i < n; ++i)
	{
		auto& src = *(from + offset * i);
		auto& dst = *(to + offset * j);
		auto& dstp = *(to + offset * (j + 1));
		if (src != 0)
		{
			if (dst == 0)
				ret = max(ret, dst = src);
			else if (src == dst)
			{
				ret = max(ret, dst <<= 1);
				++j;
				flag = true;
			}
			else
			{
				++j;
				ret = max(ret, dstp = src);
			}
		}
	}
	return ret;
}

int solution(int n, int c, int d)
{
	if (c >= 5)
		return 0;

	int ret = 0;

	// right
	flag = false;
	memset(table[c + 1], 0, 1600);
	for (int i = 0; i < n; ++i)
		ret = max(ret, solution_merge(n, &table[c][i][n - 1], &table[c + 1][i][n - 1], -1));
	if (flag || d != 0)
		ret = max(ret, solution(n, c + 1, 0));
	// left
	flag = false;
	memset(table[c + 1], 0, 1600);
	for (int i = 0; i < n; ++i)
		ret = max(ret, solution_merge(n, &table[c][i][0], &table[c + 1][i][0], 1));
	if (flag || d != 1)
		ret = max(ret, solution(n, c + 1, 1));
	// down
	flag = false;
	memset(table[c + 1], 0, 1600);
	for (int i = 0; i < n; ++i)
		ret = max(ret, solution_merge(n, &table[c][n - 1][i], &table[c + 1][n - 1][i], -20));
	if (flag || d != 2)
		ret = max(ret, solution(n, c + 1, 2));
	// up
	flag = false;
	memset(table[c + 1], 0, 1600);
	for (int i = 0; i < n; ++i)
		ret = max(ret, solution_merge(n, &table[c][0][i], &table[c + 1][0][i], 20));
	if (flag || d != 3)
		ret = max(ret, solution(n, c + 1, 3));

	return ret;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n * n; ++i)
		cin >> table[0][i / n][i % n];

	cout << solution(n, 0, -1);
}