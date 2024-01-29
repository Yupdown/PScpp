#include <bits/stdc++.h>

using namespace std;

int mat[4][4];

bool triangle(int a, int b, int c)
{
	int ml = max(max(a, b), c);
	return a + b + c >= ml * 2;
}

int main()
{
	for (int i = 0; i < 16; ++i)
		cin >> mat[i / 4][i % 4];

	int a = mat[0][1];
	int b = mat[0][2];
	int c = mat[1][2];
	int d = mat[0][3];
	int e = mat[1][3];
	int f = mat[2][3];

	bool flag = triangle(a, b, c) && triangle(a, d, e);
	if (flag)
	{
		double wa = (a * a + b * b - c * c) / static_cast<double>(a * 2);
		double wb = (a * a + e * e - d * d) / static_cast<double>(a * 2);
		double w = a - wa - wb;
		double ha = sqrt(b * b - wa * wa);
		double hb = sqrt(e * e - wb * wb);
		double llmin = w * w + (ha - hb) * (ha - hb);
		double llmax = w * w + (ha + hb) * (ha + hb);

		flag = f * f >= llmin && f * f <= llmax;
	}

	cout << (flag ? "YES" : "NO");
}