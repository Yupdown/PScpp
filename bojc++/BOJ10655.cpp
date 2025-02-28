#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

inline int distance(const pair<int, int>& from, const pair<int, int>& to)
{
	return abs(from.first - to.first) + abs(from.second - to.second);
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	pair<int, int> points[100000];
	for (int i = 0; i < n; ++i)
		cin >> points[i].first >> points[i].second;

	int sum = distance(points[0], points[1]);
	int shortcut = 0;

	for (int i = 1; i < n - 1; ++i)
	{
		int a = distance(points[i - 1], points[i]);
		int b = distance(points[i - 1], points[i + 1]);
		int c = distance(points[i], points[i + 1]);

		sum += c;
		shortcut = max(shortcut, a + c - b);
	}

	cout << sum - shortcut << '\n';
	return 0;
}