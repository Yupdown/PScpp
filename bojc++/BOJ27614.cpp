#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long r, s, h;
	cin >> r >> s >> h;
	double td = r * 2 * 3.14159265358979323846 / s / h;
	double dt = abs(td - round(td));

	tuple<int, int, int> ret;
	double vdst = 1.0;
	for (int n1 = 2; n1 <= 1000; ++n1)
	{
		for (int n2 = n1 * 2; n2 <= 1000; n2 += n1)
		{
			for (int n3 = n2 * 2; n3 <= 1000; n3 += n2)
			{
				double v = 1.0 / n1 - 1.0 / n2 + 1.0 / n3;
				if (abs(v - dt) < abs(vdst - dt))
				{
					ret = make_tuple(n1, n2, n3);
					vdst = v;
				}
			}
		}
	}
	cout << get<0>(ret) << " " << get<1>(ret) << " " << get<2>(ret);
}