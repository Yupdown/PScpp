#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<int> edges[100];

void solution(int n)
{
	vector<int> r1, r2;
	static int memo[100];
	for (int i = 0; i < n; ++i)
	{
		if (!memo[i])
		{
			queue<int> q;
			q.push(i);
			memo[i] = 1;

			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				(memo[node] & 1 ? r1 : r2).push_back(node + 1);

				for (int edge : edges[node])
				{
					if (memo[edge])
						continue;
					q.push(edge);
					memo[edge] = memo[node] + 1;
				}
			}
		}
	}

	sort(r1.begin(), r1.end());
	sort(r2.begin(), r2.end());
	cout << r1.size() << '\n';
	for (int i : r1)
		cout << i << ' ';
	cout << '\n';
	cout << r2.size() << '\n';
	for (int i : r2)
		cout << i << ' ';
	cout << '\n';
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int v;
			cin >> v;
			edges[i].push_back(v - 1);
		}
	}
	solution(n);
}