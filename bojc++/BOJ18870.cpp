#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> x[1000000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		x[i].first = i;
		cin >> x[i].second;
	}

	sort(x, x + n, [](pair<int, int>& lhs, pair<int, int>& rhs) { return lhs.second < rhs.second; });

	for (int i = 0, j = 0, k = x[0].second; i < n; i++)
	{
		if (x[i].second > k)
		{
			j += 1;
			k = x[i].second;
		}
		x[i].second = j;
	}

	sort(x, x + n, [](pair<int, int>& lhs, pair<int, int>& rhs) { return lhs.first < rhs.first; });

	for (int i = 0; i < n; i++)
		cout << x[i].second << ' ';
	cout << "\n";
}