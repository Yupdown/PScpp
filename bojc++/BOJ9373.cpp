#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

inline int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] += nodes[node1];
	nodes[node1] = node0;
}

int nodes[1002];
pair<int, int> points[1000];
int radius[1000];
vector<pair<double, pair<int, int>>> edges;

int main()
{
	FASTIO();
	PRECISION(6);

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int w, n;
		cin >> w >> n;

		for (int i = 0; i < n; ++i)
			cin >> points[i].first >> points[i].second >> radius[i];

		edges.clear();
		memset(nodes, -1, sizeof(nodes));
		edges.push_back(make_pair(w, make_pair(1000, 1001)));

		for (int i = 0; i < n; ++i)
		{
			int dx0 = max(points[i].first - radius[i], 0);
			int dx1 = max(w - points[i].first - radius[i], 0);
			edges.push_back(make_pair(dx0, make_pair(1000, i)));
			edges.push_back(make_pair(dx1, make_pair(1001, i)));

			for (int j = i + 1; j < n; ++j)
			{
				double dx = points[i].first - points[j].first;
				double dy = points[i].second - points[j].second;
				double dist = sqrt(dx * dx + dy * dy);
				edges.push_back(make_pair(max(dist - radius[i] - radius[j], 0.0), make_pair(i, j)));
			}
		}

		double result = 0.0;
		sort(edges.begin(), edges.end());
		for (auto& edge : edges)
		{
			int fp = find_node(nodes, edge.second.first);
			int tp = find_node(nodes, edge.second.second);

			if (fp != tp)
			{
				union_node(nodes, fp, tp);

				int lp = find_node(nodes, 1000);
				int rp = find_node(nodes, 1001);

				if (lp == rp)
				{
					result = edge.first;
					break;
				}
			}
		}

		cout << result * 0.5 << "\n";
	}
}