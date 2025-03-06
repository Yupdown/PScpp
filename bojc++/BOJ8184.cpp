#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<int> edges[200000];
char ret[200000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].push_back(b - 1);
		edges[b - 1].push_back(a - 1);
	}

	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if (ret[i])
			continue;
		if (edges[i].empty())
		{
			flag = true;
			break;
		}
		queue<int> q;
		q.push(i);
		ret[i] = 'K';
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (int node_next : edges[node])
			{
				if (ret[node_next])
					continue;
				q.push(node_next);
				ret[node_next] = ret[node] == 'K' ? 'S' : 'K';
			}
		}
	}

	if (flag)
		cout << "NIE\n";
	else
	{
		cout << "TAK\n";
		for (int i = 0; i < n; ++i)
			cout << ret[i] << "\n";
	}
}