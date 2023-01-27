#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	pair<int, int> xy[100];
	for (int i = 0; i < n; ++i)
		cin >> xy[i].first >> xy[i].second;

	int c = 0;
	for (int i = 0; i < 10000; ++i)
	{
		int x = i % 100;
		int y = i / 100;
		if (find_if(xy, xy + n, [&x, &y](pair<int, int> v) { return x >= v.first && x < v.first + 10 && y >= v.second && y < v.second + 10; }) != xy + n)
			++c;
	}

	cout << c << endl;
}