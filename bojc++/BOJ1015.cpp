#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	pair<int, int> pairs[50];
	for (int i = 0; i < n; ++i)
	{
		int ai;
		cin >> ai;
		pairs[i] = make_pair(ai, i);
	}

	sort(pairs, pairs + n);

	for (int i = 0; i < n; ++i)
		pairs[pairs[i].second].first = i;

	for (int i = 0; i < n; ++i)
		cout << pairs[i].first << ' ';
	cout << endl;

	return 0;
}