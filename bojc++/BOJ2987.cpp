#include <bits/stdc++.h>
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int tri[3][2];

inline int cross_product(int ax, int ay, int bx, int by)
{
	return (ax * by) - (ay * bx);
}

inline int sqr_magnitude(int x, int y)
{
	return x * x + y * y;
}

int main()
{
	PRECISION(1);

	for (int i = 0; i < 6; ++i)
		cin >> tri[i / 2][i % 2];

	int product = cross_product(tri[1][0] - tri[0][0], tri[1][1] - tri[0][1], tri[2][0] - tri[0][0], tri[2][1] - tri[0][1]);
	if (product < 0)
	{
		swap(tri[1][0], tri[2][0]);
		swap(tri[1][1], tri[2][1]);
	}

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		bool flag = true;
		for (int j = 0; j < 3; ++j)
		{
			int* ta = tri[j];
			int* tb = tri[(j + 1) % 3];
			flag &= cross_product(tb[0] - ta[0], tb[1] - ta[1], x - ta[0], y - ta[1]) >= 0;
			if (product == 0)
				flag &= sqr_magnitude(x - ta[0], y - ta[1]) + sqr_magnitude(x - tb[0], y - tb[1]) <= sqr_magnitude(ta[0] - tb[0], ta[1] - tb[1]);

		}
		cnt += flag;
	}

	cout << abs<double>(product) / 2 << '\n' << cnt;
}