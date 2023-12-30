#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int node_distance[500];
int node_visited[500][500];
vector<int> node_parent[500];
vector<pair<int, int>> edges[500];

int dijkstra(int n, int start, int end)
{
	priority_queue<pair<int, int>> next_nodes;

	for (int i = 0; i < n; ++i)
	{
		node_distance[i] = i == start ? 0 : INT_MAX;
		node_parent[i].clear();
	}

	next_nodes.push(make_pair(0, start));
	while (!next_nodes.empty())
	{
		int node = next_nodes.top().second;
		next_nodes.pop();

		for (const auto& next : edges[node])
		{
			if (node_visited[node][next.first])
				continue;

			int value = node_distance[node] + next.second;

			if (value < node_distance[next.first])
			{
				next_nodes.push(make_pair(-value, next.first));
				node_distance[next.first] = value;
				node_parent[next.first].clear();
			}
			if (value <= node_distance[next.first])
				node_parent[next.first].push_back(node);
		}
	}

	return node_distance[end] == INT_MAX ? -1 : node_distance[end];
}

void flag_visited(int start, int end)
{
	if (start == end)
		return;

	for (int parent : node_parent[end])
	{
		if (node_visited[parent][end])
			continue;

		node_visited[parent][end] = 1;
		flag_visited(start, parent);
	}
}

int main()
{
	FASTIO();

	int n, m, s, d;

	while (cin >> n >> m)
	{
		if (!n && !m)
			break;

		cin >> s >> d;

		memset(node_visited, 0, sizeof(node_visited));
		for (int i = 0; i < n; ++i)
			edges[i].clear();

		for (int i = 0; i < m; ++i)
		{
			int u, v, p;
			cin >> u >> v >> p;
			edges[u].push_back(make_pair(v, p));
		}

		dijkstra(n, s, d);
		flag_visited(s, d);
		cout << dijkstra(n, s, d) << "\n";
	}
}