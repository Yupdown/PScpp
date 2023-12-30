#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[32];
int bit_field;
int frag[5];
int perm[5];

int solution(int n, int i, int v)
{
	if (i < n)
	{
		int ret = INT_MAX;
		for (int j = v + 1; j < 25; ++j)
		{
			perm[i] = j;
			bit_field |= 1 << j;
			ret = min(ret, solution(n, i + 1, j));
			bit_field &= ~(1 << j);
		}
		return ret;
	}

	queue<int> q;
	q.push(perm[0]);
	int visited = bit_field & ~(1 << perm[0]);
	int c = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		++c;

		int next[4] = { cur - 5, cur + 5, cur - 1, cur + 1 };
		for (int i = 0; i < 4; ++i)
		{
			if (i == 2 && cur % 5 == 0)
				continue;
			if (i == 3 && cur % 5 == 4)
				continue;
			if (next[i] < 0 || next[i] >= 25)
				continue;

			if (visited & (1 << next[i]))
			{
				visited &= ~(1 << next[i]);
				q.push(next[i]);
			}
		}
	}
	if (c < n)
		return INT_MAX;

	int ret = INT_MAX;
	do
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			int dx = frag[j] / 5 - perm[j] / 5;
			int dy = frag[j] % 5 - perm[j] % 5;
			sum += abs(dx) + abs(dy);
		}
		ret = min(ret, sum);
	} while (next_permutation(perm, perm + n));

	return ret;
}

int main()
{
	FASTIO();

	for (int i = 0; i < 5; ++i)
		cin >> table + i * 5;

	int n = 0;
	for (int i = 0; i < 25; ++i)
	{
		if (table[i] == '*')
			frag[n++] = i;
	}

	cout << solution(n, 0, -1);
}