#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> room_range[1000];
int memo[1000][2];

int solution(int h, int x, int y, int c)
{
	if (x == h)
		return -100;
	if (memo[x][c] < 0xF0F0F0F0)
		return memo[x][c];
	if (room_range[x].second == 0)
		return memo[x][c] = solution(h, x + 1, y, c) + 100;
	return memo[x][c] = min(
		solution(h, x + 1, room_range[x].first, 0) + abs(room_range[x].second - y),
		solution(h, x + 1, room_range[x].second, 1) + abs(room_range[x].first - y))
		+ 100 + room_range[x].second - room_range[x].first;
}

int main()
{
	FASTIO();

	int n, h, w;
	cin >> n >> h >> w;
	memset(memo, 0xF0, sizeof(memo));
	room_range[0] = make_pair(1, 1);
	for (int i = 1; i < h; ++i)
		room_range[i] = make_pair(w, 0);
	int xmax = 0;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		xmax = max(xmax, x);
		room_range[x - 1].first = min(room_range[x - 1].first, y);
		room_range[x - 1].second = max(room_range[x - 1].second, y);
	}
	cout << solution(xmax, 0, 1, 0);
}