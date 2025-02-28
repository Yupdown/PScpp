#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

struct graph_edge
{
	int node0;
	int node1;
	int weight;
};

int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] = node1;
}

int main()
{
	int v, e, r = 0;
	cin >> v >> e;

	int nodes[10000];
	memset(nodes, -1, sizeof(int) * v);

	graph_edge edges[100000];
	for (int i = 0; i < e; i++)
	{
		cin >> edges[i].node0 >> edges[i].node1 >> edges[i].weight;

		edges[i].node0 -= 1;
		edges[i].node1 -= 1;
	}

	sort(edges, edges + e, [](graph_edge a, graph_edge b) -> bool { return a.weight < b.weight; });

	for (int i = 0; i < e; i++)
	{
		int rootA = find_node(nodes, edges[i].node0);
		int rootB = find_node(nodes, edges[i].node1);
		if (rootA == rootB)
			continue;

		union_node(nodes, rootA, rootB);
		r += edges[i].weight;
	}

	cout << r << endl;
	return 0;
}