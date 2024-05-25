#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<pair<int, int>> table[10000];
int values[10000];

bool solution(int b, int e, int c)
{
	memset(values, 0, sizeof(values));
	queue<int> q;
	q.push(b);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == e)
			return true;
		for (auto [nxt, cost] : table[cur])
		{
			if (cost < c || values[nxt] > 0)
				continue;
			values[nxt] = 1;
			q.push(nxt);
		}
	}
	return false;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		table[a - 1].push_back(make_pair(b - 1, c));
		table[b - 1].push_back(make_pair(a - 1, c));
	}

	int b, e;
	cin >> b >> e;

	int x = 0;
	for (int dx = 1 << 29; dx; dx >>= 1)
	{
		if (solution(b - 1, e - 1, x + dx))
			x += dx;
	}

	cout << x;
}