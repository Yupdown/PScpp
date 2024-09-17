#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

pair<int, int> table[200];
vector<tuple<int, int, int>> edges;
int nodes[200];

inline int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] += nodes[node1];
	nodes[node1] = node0;
}

int main()
{
	FASTIO();
	PRECISION(3);

	int n, c = 0;
	edges.reserve(40000);
	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
			cin >> table[i].first >> table[i].second;
		edges.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int dx = table[i].first - table[j].first;
				int dy = table[i].second - table[j].second;
				edges.emplace_back(make_tuple(dx * dx + dy * dy, i, j));
			}
		}
		sort(edges.begin(), edges.end());
		memset(nodes, -1, sizeof(nodes));
		int ret;
		for (const auto& [w, i, j] : edges)
		{
			int ip = find_node(nodes, i);
			int jp = find_node(nodes, j);
			if (ip == jp)
				continue;
			union_node(nodes, ip, jp);
			if (find_node(nodes, 0) == find_node(nodes, 1))
			{
				ret = w;
				break;
			}
		}
		cout << "Scenario #" << ++c << "\nFrog Distance = " << sqrt(ret) << "\n\n";
	}
}