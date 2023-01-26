#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<pair<int, pair<int, int>>> edge;
queue<pair<int, int>> pairs;
int nodes[1024];

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
	for (int i = 0; i < n; ++i) {
		nodes[i] = -1;
		for (int j = 0; j < n; ++j) {
			int v;
			cin >> v;
			if (i >= j)
				continue;
			edge.push_back(make_pair(v, make_pair(i, j)));
		}
	}

	sort(edge.begin(), edge.end());

	int c = 0;
	int m = 0;
	for (auto element : edge) {
		int p1 = find_node(nodes, element.second.first);
		int p2 = find_node(nodes, element.second.second);
		if (element.first < 0) {
			if (p1 != p2)
				union_node(nodes, p1, p2);
			c -= element.first;
		}
		else {
			if (p1 != p2) {
				union_node(nodes, p1, p2);
				pairs.push(element.second);
				c += element.first;
				++m;
			}
		}
	}

	cout << c << ' ' << m << '\n';
	while (!pairs.empty()) {
		pair<int, int> p = pairs.front();
		pairs.pop();
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
}