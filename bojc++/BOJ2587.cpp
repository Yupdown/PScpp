#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int v[5], s = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> v[i];
		s += v[i];
	}

	sort(v, v + 5);
	cout << s / 5 << "\n" << v[2] << "\n";
}