#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<int> edges[300000];

int solution(int n)
{
	int r = 0;
	static int memo[300000];
	for (int i = 0; i < n; ++i)
	{
		if (edges[i].size() > 0 && !memo[i])
		{
			queue<int> q;
			q.push(i);
			memo[i] = 1;

			int rp0 = 0;
			int rp1 = 0;
			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				(memo[node] & 1 ? rp0 : rp1)++;

				for (int edge : edges[node])
				{
					if (memo[edge])
					{
						if (~(memo[node] ^ memo[edge]) & 1)
							return -1;
						continue;
					}
					q.push(edge);
					memo[edge] = memo[node] + 1;
				}
			}
			r += min(rp0, rp1);
		}
	}
	return r;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		edges[x - 1].push_back(y - 1);
		edges[y - 1].push_back(x - 1);
	}
	cout << solution(n);
}