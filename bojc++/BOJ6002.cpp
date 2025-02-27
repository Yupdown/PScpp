#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<tuple<int, int, int>> edges;
int dist[220];

int main()
{
	FASTIO();

	int d, p, c, f, s;
	cin >> d >> p >> c >> f >> s;

	for (int i = 0; i < p; ++i)
	{
		int ai, bi;
		cin >> ai >> bi;
		edges.emplace_back(ai - 1, bi - 1, -d);
	}
	for (int i = 0; i < f; ++i)
	{
		int ji, ki, ti;
		cin >> ji >> ki >> ti;
		edges.emplace_back(ji - 1, ki - 1, ti - d);
	}

	memset(dist, 0x10, sizeof(dist));
	dist[s - 1] = -d;
	for (int i = 0; i < c; ++i)
	{
		for (const auto& [j, k, t] : edges)
		{
			if (dist[j] != 0x10101010 && dist[j] + t < dist[k])
			{
				dist[k] = dist[j] + t;
				if (i == c - 1)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << -*min_element(dist, dist + c);
}