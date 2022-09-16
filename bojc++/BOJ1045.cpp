#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int nodes[50];
int result[50];
vector<pair<int, int>> tuples;

int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

void union_node(int* nodes, int node0, int node1)
{
	nodes[node1] = nodes[node0] - 1;
	nodes[node0] = node1;
}

void add_result(pair<int, int> tuple)
{
	++result[tuple.first];
	++result[tuple.second];
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		nodes[i] = -1;

		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;

			if (i < j && c == 'Y')
				tuples.push_back(make_pair(min(i, j), max(i, j)));
		}
	}

	int major = 0;
	int minor = 0;
	for (pair<int, int> tuple : tuples)
	{
		int pi = find_node(nodes, tuple.first);
		int pj = find_node(nodes, tuple.second);

		if (pi != pj)
		{
			union_node(nodes, pi, pj);
			add_result(tuple);
			++major;
		}
		else if (minor <= m - n)
		{
			add_result(tuple);
			++minor;
		}
	}

	if (major < n - 1 || major + minor < m)
		cout << -1;
	else
	{
		for (int i = 0; i < n; ++i)
			cout << result[i] << ' ';
	}
	cout << endl;

	return 0;
}