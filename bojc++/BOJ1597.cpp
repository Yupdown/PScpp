#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char mapping[] = ".+o$#";
pair<int, int> table[100];
double memo[100][100];

int main()
{
	FASTIO();

	int n, w, h;
	cin >> n >> w >> h;
	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;
	for (int i = 0; i < n; ++i)
	{
		const auto& [fx, fy] = table[i];
		const auto& [tx, ty] = table[(i + 1) % n];
		// 해당 line segment가 수직일 경우 연산에서 제외
		if (fx == tx)
			continue;
		for (int x = min(fx, tx); x < max(fx, tx); ++x)
		{
			double ay = fy + static_cast<double>((fx - x) * (ty - fy)) / (fx - tx);
			double by = fy + static_cast<double>((fx - x - 1) * (ty - fy)) / (fx - tx);
			double ax = x;
			double bx = x + 1;
			if (ay > by)
			{
				swap(ax, bx);
				swap(ay, by);
			}
			int iay = static_cast<int>(ay);
			int iby = static_cast<int>(by);
			double sgn = fx < tx ? 1 : -1;
			for (int y = 0; y < iay; ++y)
				memo[x][y] += sgn;
			memo[x][iay] += (ay - iay) * sgn;
			if (ay < by)
			{
				if (by <= iay + 1)
					memo[x][iay] += (by - ay) * 0.5 * sgn;
				else
				{
					memo[x][iay] += (1 + (by - iay - 1) / (by - ay)) * 0.5 * (iay + 1 - ay) * sgn;
					for (int y = iay + 1; y < iby; ++y)
						memo[x][y] += ((by - y) + (by - y - 1)) / (by - ay) * 0.5 * sgn;
					memo[x][iby] += (by - iby) * (by - iby) / (by - ay) * 0.5 * sgn;
				}
			}
		}
	}
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
			cout << mapping[min(static_cast<int>(abs((memo[x][h - y - 1]) + 1e-9) * 4), 4)];
		cout << "\n";
	}
}