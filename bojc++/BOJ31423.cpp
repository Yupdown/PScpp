#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

string str[500000];
vector<int> edge[500000];
int adj[500000];

void func(int c)
{
	cout << str[c];
	for (int e : edge[c])
		func(e);
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> str[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		adj[b - 1]++;
	}

	for (int i = 0; i < n; ++i)
	{
		if (adj[i] == 0)
		{
			func(i);
			break;
		}
	}
}