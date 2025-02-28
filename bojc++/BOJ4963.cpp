#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[50][50];

void solution(int w, int h, int x, int y)
{
	table[y][x] = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (!i && !j)
				continue;
			int xp = x + i;
			int yp = y + j;
			if (xp < 0 || xp >= w)
				continue;
			if (yp < 0 || yp >= h)
				continue;
			if (!table[yp][xp])
				continue;
			solution(w, h, xp, yp);
		}
	}
}

int main()
{
	FASTIO();

	while (true) {
		int w, h;
		cin >> w >> h;

		if (!w && !h)
			break;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				cin >> table[i][j];
		}

		int c = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (!table[i][j])
					continue;
				solution(w, h, j, i);
				++c;
			}
		}
		cout << c << '\n';
	}
}