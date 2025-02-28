#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

struct graph_edge
{
	int node0;
	int node1;
	double weight;
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
	double r = 0.0;

	double x[100];
	double y[100];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	int nodes[100];
	memset(nodes, -1, sizeof(int) * n);

	graph_edge edges[10000];
	for (int i = 0; i < n * n; i++)
	{
		int node0 = i / n;
		int node1 = i % n;

		edges[i].node0 = node0;
		edges[i].node1 = node1;
		edges[i].weight = sqrt(pow(x[node1] - x[node0], 2.0) + pow(y[node1] - y[node0], 2.0));
	}

	sort(edges, edges + n * n, [](graph_edge a, graph_edge b) -> bool { return a.weight < b.weight; });

	for (int i = 0; i < n * n; i++)
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