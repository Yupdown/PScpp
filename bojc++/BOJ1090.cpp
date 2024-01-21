#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int xc[50];
int yc[50];
int rc[50];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> xc[i] >> yc[i];
		rc[i] = INT_MAX;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x = xc[i];
			int y = yc[j];

			for (int k = 0; k < n; ++k)
				pq.push(abs(xc[k] - x) + abs(yc[k] - y));
			for (int k = 0, s = 0; k < n; ++k, pq.pop())
			{
				s += pq.top();
				rc[k] = min(rc[k], s);
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << rc[i] << ' ';
}