#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int ev[100000];
pair<int, int> input[100000][18];
vector<pair<int, int>> edges[100000];

void make_table(int current, int last)
{
	for (const pair<int, int>& edge : edges[current]) {
		if (edge.first == last)
			continue;

		input[edge.first][0] = make_pair(current, edge.second);
		make_table(edge.first, current);
	}
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> ev[i];

	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a - 1].push_back(make_pair(b - 1, c));
		edges[b - 1].push_back(make_pair(a - 1, c));
	}

	make_table(0, 0);
	for (int i = 1; i < 18; ++i) {
		for (int j = 0; j < n; ++j) {
			pair<int, int> stop = input[input[j][i - 1].first][i - 1];
			input[j][i] = make_pair(stop.first, input[j][i - 1].second + stop.second);
		}
	}

	for (int i = 0; i < n; ++i) {
		int r = i;
		while (r != 0 && ev[i] >= input[r][0].second) {
			int next = 0;
			while (next < 18 && ev[i] >= input[r][next].second)
				++next;

			ev[i] -= input[r][next - 1].second;
			r = input[r][next - 1].first;
		}
		cout << r + 1 << "\n";
	}
}