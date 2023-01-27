#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char matrix[1024][1024];
char matrix_temp[1024][1024];

pair<int, int> offset[] {
	make_pair(1, 0),
	make_pair(-1, 0),
	make_pair(0, 1),
	make_pair(0, -1)
};

int get_result(int n, int m)
{
	queue<pair<int, int>> route;
	route.push(make_pair(0, 0));
	matrix_temp[0][0] = 1;

	int c = 1;
	while (!route.empty()) {
		int size = route.size();
		for (int i = 0; i < size; ++i) {
			pair<int, int> current = route.front();
			route.pop();

			if (current.first == n - 1 && current.second == m - 1)
				return c;

			for (int j = 0; j < 4; ++j) {
				pair<int, int> next_node = make_pair(current.first + offset[j].first, current.second + offset[j].second);

				if (next_node.first < 0 || next_node.first >= n || next_node.second < 0 || next_node.second >= m)
					continue;

				char current_type = matrix_temp[current.first][current.second];
				char next_type = matrix_temp[next_node.first][next_node.second];
				if (next_type && next_type <= current_type)
					continue;

				bool wall = matrix[next_node.first][next_node.second] == '1';
				if (wall) {
					if (current_type > 1)
						continue;
					else
						current_type += 1;
				}

				route.push(next_node);
				matrix_temp[next_node.first][next_node.second] = next_type > 0 ? min(next_type, current_type) : current_type;
			}
		}
		++c;
	}

	return -1;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> matrix[i];

	cout << get_result(n, m);
}