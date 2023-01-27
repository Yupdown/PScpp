#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> positions[1000];
double matrix[1000][1000];
vector<pair<pair<int, int>, double>> edges;
int nodes[1000];

int FindNode(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = FindNode(nodes, nodes[node]));
}

void UnionNode(int* nodes, int node0, int node1)
{
	nodes[node0] = node1;
}

inline double Distance(pair<int, int> lhs, pair<int, int> rhs)
{
	double dx = rhs.first - lhs.first;
	double dy = rhs.second - lhs.second;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	FASTIO();

	cout << fixed;
	cout.precision(2);

	int n, m;
	cin >> n >> m;

	memset(nodes, -1, sizeof(int) * n);

	for (int i = 0; i < n; ++i)
		cin >> positions[i].first >> positions[i].second;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
			matrix[i][j] = Distance(positions[i], positions[j]);
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		matrix[a - 1][b - 1] = 0;
		matrix[b - 1][a - 1] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
			edges.push_back(make_pair(make_pair(i, j), matrix[i][j]));
	}

	sort(edges.begin(), edges.end(), [](const pair<pair<int, int>, double>& lhs, const pair<pair<int, int>, double>& rhs) { return lhs.second < rhs.second; });

	double result{ 0.0 };
	for (pair<pair<int, int>, double> edge : edges)
	{
		int rootA = FindNode(nodes, edge.first.first);
		int rootB = FindNode(nodes, edge.first.second);
		if (rootA == rootB)
			continue;

		UnionNode(nodes, rootA, rootB);
		result += edge.second;
	}

	cout << result << endl;
}