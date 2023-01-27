#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int node[10000];

void Function(int from, int to)
{
	if (from == to)
		return;
	int mid = find_if(node + from, node + to, [=](int value) { return value > node[from]; }) - node;
	Function(from + 1, mid);
	Function(mid, to);
	cout << node[from] << "\n";
}

int main()
{
	FASTIO();
	int n = 0;
	while (cin >> node[n++]);
	Function(n, 0);
}