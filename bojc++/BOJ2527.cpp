#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int condition(int imin, int imax, int jmin, int jmax)
{
	if (imin == jmax || imax == jmin)
		return 0;
	if (imin > jmax || imax < jmin)
		return -1;
	return 1;
}

int main()
{
	FASTIO();

	int x1, y1, p1, q1;
	int x2, y2, p2, q2;
	while (cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2)
	{
		int c1 = condition(x1, p1, x2, p2);
		int c2 = condition(y1, q1, y2, q2);

		if (c1 + c2 == 2)
			cout << "a\n";
		else if (c1 + c2 == 1)
			cout << "b\n";
		else if (!c1 && !c2)
			cout << "c\n";
		else
			cout << "d\n";
	}

	return 0;
}