#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int result[20000];
vector<pair<int, int>> edge[20000];
priority_queue<pair<int, int>> search_queue;

int main()
{
	FASTIO();

	int v, e, k;
	cin >> v >> e >> k;

	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u - 1].push_back(make_pair(v - 1, w));
	}

	for (int i = 0; i < v; ++i)
		result[i] = i != k - 1 ? INT32_MAX : 0;
	search_queue.push(make_pair(0, k - 1));

	while (!search_queue.empty()) {
		int current_node = search_queue.top().second;
		search_queue.pop();

		for (const pair<int, int>& next_node : edge[current_node]) {
			int value = result[current_node] + next_node.second;
			if (value < result[next_node.first]) {
				result[next_node.first] = value;
				search_queue.push(make_pair(-value, next_node.first));
			}
		}
	}

	for (int i = 0; i < v; ++i) {
		if (i == k - 1)
			cout << 0;
		else if (result[i] < INT32_MAX)
			cout << result[i];
		else
			cout << "INF";
		cout << "\n";
	}
}