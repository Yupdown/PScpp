#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

//int table[50][50];
//
//void solution(int w, int h, int x, int y)
//{
//	table[y][x] = 0;
//	for (int i = -1; i <= 1; ++i) {
//		for (int j = -1; j <= 1; ++j) {
//			if (!i && !j)
//				continue;
//			int xp = x + i;
//			int yp = y + j;
//			if (xp < 0 || xp >= w)
//				continue;
//			if (yp < 0 || yp >= h)
//				continue;
//			if (!table[yp][xp])
//				continue;
//			solution(w, h, xp, yp);
//		}
//	}
//}
//
//int main()
//{
//	FASTIO();
//
//	while (true) {
//		int w, h;
//		cin >> w >> h;
//
//		if (!w && !h)
//			break;
//
//		for (int i = 0; i < h; ++i) {
//			for (int j = 0; j < w; ++j)
//				cin >> table[i][j];
//		}
//
//		int c = 0;
//		for (int i = 0; i < h; ++i) {
//			for (int j = 0; j < w; ++j) {
//				if (!table[i][j])
//					continue;
//				solution(w, h, j, i);
//				++c;
//			}
//		}
//		cout << c << '\n';
//	}
//}

int samp[1024];
int memo[101][101];

int main()
{
	FASTIO();

	samp[0] = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 1 << i; ++j)
			samp[(1 << i) + j] = (samp[(1 << i) - j - 1] + 1) % 4;
	}

	int n;
	cin >> n;
	while (n--)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		memo[x][y] = 1;
		for (int i = 0; i < 1 << g; ++i)
		{
			switch ((samp[i] + d) % 4)
			{
			case 0:
				x++;
				break;
			case 1:
				y--;
				break;
			case 2:
				x--;
				break;
			case 3:
				y++;
				break;
			}
			if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
				memo[x][y] = 1;
		}
	}

	int ret = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
			ret += memo[i][j] + memo[i + 1][j] + memo[i][j + 1] + memo[i + 1][j + 1] >> 2;
	}
	cout << ret;
}