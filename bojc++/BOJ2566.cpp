#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();
	pair<int, int> vmax;
	for (int i = 0; i < 81; ++i)
	{
		int v;
		cin >> v;
		if (v >= vmax.first)
			vmax = make_pair(v, i);
	}
	cout << vmax.first << "\n" << (vmax.second / 9) + 1 << " " << (vmax.second % 9) + 1 << "\n";
}