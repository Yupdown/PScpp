#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100001];
int visited[100001];

int function_search(int x)
{
	if (!x)
		return 0;
	if (!visited[x])
	{
		visited[x] = 1;
		return x;
	}
	if (table[x] > 0)
		return table[x] = function_search(table[x]);
	return table[x] = function_search(x - 1);
}

int main()
{
	FASTIO();

	int g, p;
	cin >> g >> p;

	for (int i = 0; i < p; ++i)
	{
		int gi;
		cin >> gi;
		if (!function_search(gi))
			break;
	}

	cout << accumulate(visited + 1, visited + g + 1, 0);
}