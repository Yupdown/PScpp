#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

int dp[1001][1001];
pair<int, int> cases[1001];

inline int distance(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int function(int n, int w, int a, int b)
{
	if (a >= w || b >= w)
		return 0;

	int* ref = &dp[a][b];

	if (*ref < 0)
	{
		int next = max(a, b) + 1;
		int distA = distance(a > 0 ? cases[a - 1] : make_pair(1, 1), cases[next - 1]);
		int distB = distance(b > 0 ? cases[b - 1] : make_pair(n, n), cases[next - 1]);

		*ref = min(function(n, w, next, b) + distA, function(n, w, a, next) + distB);
	}

	return *ref;
}

void print_result(int n, int w, int a, int b)
{
	if (a >= w || b >= w)
		return;

	int next = max(a, b) + 1;

	int distA = distance(a > 0 ? cases[a - 1] : make_pair(1, 1), cases[next - 1]);
	int distB = distance(b > 0 ? cases[b - 1] : make_pair(n, n), cases[next - 1]);

	if (function(n, w, next, b) + distA < function(n, w, a, next) + distB)
	{
		cout << 1 << endl;
		print_result(n, w, next, b);
	}
	else
	{
		cout << 2 << endl;
		print_result(n, w, a, next);
	}
}

int main()
{
	int n, w;
	cin >> n >> w;

	for (int i = 0; i < w; ++i)
		cin >> cases[i].first >> cases[i].second;

	memset(dp, -1, sizeof(dp));
	function(n, w, 0, 0);

	cout << dp[0][0] << endl;
	print_result(n, w, 0, 0);

	return 0;
}