#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> points[600000];
stack<int> s;
int integrity[300000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x, r;
		cin >> x >> r;

		points[i * 2] = make_pair(x - r, i);
		points[i * 2 + 1] = make_pair(x + r, -1);
	}

	sort(points, points + n * 2);

	s.push(points[0].second);
	for (int i = 1; i < n * 2; ++i)
	{
		if (points[i - 1].first < points[i].first)
			integrity[s.top()] = 1;
		if (points[i].second < 0)
			s.pop();
		else
			s.push(points[i].second);
	}

	int sum = 1;
	for (int i = 0; i < n; ++i)
		sum += 2 - integrity[i];

	cout << sum;
}