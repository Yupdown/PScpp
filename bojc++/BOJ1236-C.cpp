#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> xp[100000];
int dist[100000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> xp[i].first >> xp[i].second;

	sort(xp, xp + n);

	for (int i = 1; i < n; ++i)
		dist[i] = xp[i].first - xp[i - 1].first;


}