#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] = node1;
}

pair<int, int> xPair[100000];
pair<int, int> yPair[100000];
pair<int, int> zPair[100000];

pair<int, pair<int, int>> edges[300000];

int nodes[100000];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		xPair[i].second = i;
		yPair[i].second = i;
		zPair[i].second = i;

		cin >> xPair[i].first >> yPair[i].first >> zPair[i].first;
	}

	sort(xPair, xPair + n);
	sort(yPair, yPair + n);
	sort(zPair, zPair + n);

	for (int i = 0; i < n - 1; i++)
	{
		edges[i * 3] = { abs(xPair[i].first - xPair[i + 1].first), { xPair[i].second, xPair[i + 1].second } };
		edges[i * 3 + 1] = { abs(yPair[i].first - yPair[i + 1].first), { yPair[i].second, yPair[i + 1].second } };
		edges[i * 3 + 2] = { abs(zPair[i].first - zPair[i + 1].first), { zPair[i].second, zPair[i + 1].second } };
	}

	sort(edges, edges + (n * 3));

	for (int i = 0; i < n; i++)
		nodes[i] = -1;

	int result = 0;

	for (int i = 0; i < n * 3; i++)
	{
		int rootA = find_node(nodes, edges[i].second.first);
		int rootB = find_node(nodes, edges[i].second.second);
		if (rootA == rootB)
			continue;

		union_node(nodes, rootA, rootB);
		result += edges[i].first;
	}

	cout << result << endl;
	return 0;
}