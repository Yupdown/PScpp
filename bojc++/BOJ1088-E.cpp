#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int h[200];
int l[200];

int main()
{
	FASTIO();

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		++h[v];
	}
	for (int i = 0; i < m; ++i)
		cin >> l[i];
}