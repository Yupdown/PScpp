#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edge[50000];
vector<int> result;
int visited[50000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		stack<int> dfs;
		dfs.push((i + 1) % n);
		while (!dfs.empty())
		{
			int node = dfs.top();
			dfs.pop();

			if (visited[node] || node == i)
				continue;
			visited[node] = true;

			for (int next_node : edge[node])
				dfs.push(next_node);
			++cnt;
		}

		if (cnt < n - 1)
			result.push_back(i + 1);
	}

	cout << result.size() << '\n';
	for (int element : result)
		cout << element << '\n';
}