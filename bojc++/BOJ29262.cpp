#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

map<int, int> ftox;
map<int, int> xtof;
map<int, int> pos;

void rotate_cube(int n, int dn, int fw)
{
	int dnx = 1;
	int fwx = fw;

	if (ftox.find(fwx) != ftox.end())
		fwx = ftox[fwx];

	int seq_f[4] = {};
	int seq_x[4] = { dnx, fwx, n * 2 + 1 - dnx, n * 2 + 1 - fwx };

	for (int i = 0; i < 4; ++i)
	{
		if (xtof.find(seq_x[i]) != xtof.end())
			seq_f[i] = xtof[seq_x[i]];
		else
			seq_f[i] = seq_x[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		ftox[seq_f[(i + 1) % 4]] = seq_x[i];
		xtof[seq_x[i]] = seq_f[(i + 1) % 4];
	}
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	int x1f = 1;
	for (int i = 0; i < m; ++i)
	{
		int v;
		cin >> v;

		int vx = v;
		if (ftox.find(vx) != ftox.end())
			vx = ftox[vx];

		pair<int, int> p;
		if (vx > n)
			p = make_pair(n * 2 + 1 - vx, -1);
		else
			p = make_pair(vx, 1);

		if (pos.find(p.first) == pos.end())
			pos[p.first] = p.second;
		else
			pos[p.first] += p.second;

		rotate_cube(n, x1f, v);
		x1f = v;
	}

	int64_t r = 0;
	for (auto& p : pos)
	{
		int64_t x = p.second;
		r += x * x;
	}

	cout << r;
}