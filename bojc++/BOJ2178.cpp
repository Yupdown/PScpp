#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[128][128];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	cout << [](int n, int m) {
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		int c = 1;
		while (!q.empty()) {
			int l = q.size();
			while (l-- > 0) {
				pair<int, int> front = q.front();
				q.pop();

				if (front.first == n - 1 && front.second == m - 1)
					return c;

				int next[][2] = {
					front.first + 1, front.second,
					front.first - 1, front.second,
					front.first, front.second + 1,
					front.first, front.second - 1,
				};

				for (int i = 0; i < 4; ++i) {
					if (next[i][0] < 0 || next[i][0] >= n || next[i][1] < 0 || next[i][1] >= m)
						continue;
					if (table[next[i][0]][next[i][1]] != '1')
						continue;
					table[next[i][0]][next[i][1]] = '0';
					q.push(make_pair(next[i][0], next[i][1]));
				}
			}
			++c;
		}
		return -1;
	}(n, m);
}