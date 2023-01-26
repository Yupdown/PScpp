#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int result[1000];
vector<pair<int, int>> edge[1000];
priority_queue<pair<int, int>> search_queue;

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u - 1].push_back(make_pair(v - 1, w));
	}

	int k, e;
	cin >> k >> e;

	for (int i = 0; i < n; ++i)
		result[i] = i != k - 1 ? INT32_MAX : 0;
	search_queue.push(make_pair(0, k - 1));

	while (!search_queue.empty()) {
		int current_node = search_queue.top().second;
		int current_cost = -search_queue.top().first;
		search_queue.pop();
		if (current_cost > result[current_node])
			continue;

		for (const pair<int, int>& next_node : edge[current_node]) {
			int value = result[current_node] + next_node.second;
			if (value < result[next_node.first]) {
				result[next_node.first] = value;
				search_queue.push(make_pair(-value, next_node.first));
			}
		}
	}

	cout << result[e - 1] << "\n";
}