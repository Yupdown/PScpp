#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

	int n, l = 0, kmax = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;

		l += k;
		kmax = k > kmax ? k : kmax;
	}

	int dx = x2 - x1;
	int dy = y2 - y1;
	int dz = z2 - z1;
	double dist = sqrt(dx * dx + dy * dy + dz * dz);
	int v = kmax * 2 - l;

	cout << (dist <= l && dist >= kmax * 2 - l ? "YES" : "NO") << endl;
	return 0;
}