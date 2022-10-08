#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int nodes[301];

struct node_edge
{
	int a, b, v;
};

vector<node_edge> edges;

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

	int n;
	cin >> n;

	nodes[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		int cost;
		cin >> cost;

		edges.push_back({ 0, i + 1, cost });
		nodes[i + 1] = -1;
	}
	
	for (int i = 0; i < n * n; ++i)
	{
		int v;
		cin >> v;
		
		if (i % n > i / n)
			edges.push_back({ i / n + 1, i % n + 1, v });
	}

	sort(edges.begin(), edges.end(), [](const node_edge& a, const node_edge& b) -> bool { return a.v < b.v; });

	int result = 0;

	for (node_edge edge : edges)
	{
		int pa = find_node(nodes, edge.a);
		int pb = find_node(nodes, edge.b);

		if (pa == pb)
			continue;

		union_node(nodes, pa, pb);
		result += edge.v;
	}

	cout << result << endl;
	return 0;
}