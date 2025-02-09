#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<int> edges[1000];

int solution(int n)
{
	static int memo[1000];
	memset(memo, 0, sizeof(memo));
	for (int i = 0; i < n; ++i)
	{
		if (edges[i].size() > 0 && !memo[i])
		{
			queue<int> q;
			q.push(i);
			memo[i] = 1;

			while (!q.empty())
			{
				int node = q.front();
				q.pop();

				for (int edge : edges[node])
				{
					if (memo[edge])
					{
						if (~(memo[node] ^ memo[edge]) & 1)
							return 0;
						continue;
					}
					q.push(edge);
					memo[edge] = memo[node] + 1;
				}
			}
		}
	}
	return 1;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			edges[i].clear();
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			edges[x - 1].push_back(y - 1);
			edges[y - 1].push_back(x - 1);
		}
		cout << (solution(n) ? "possible\n" : "impossible\n");
	}
}