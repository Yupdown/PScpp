#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int mat[]{ 4, -1, 1, 0 };

int main()
{
	FASTIO();

	int n;
	cin >> n;

	int v[] = { 1, 1 };
	decltype(v) vp;

	for (int i = 0; i << 1 < n; ++i)
	{
		vp[0] = v[0] * mat[0] + v[1] * mat[1];
		vp[1] = v[0] * mat[2] + v[1] * mat[3];
		copy(begin(vp), end(vp), begin(v));
	}

	cout << (n & 1 ? 0 : v[0]);
}