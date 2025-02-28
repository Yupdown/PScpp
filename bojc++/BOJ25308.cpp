#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool ccw(double a, double b, double c)
{
	return -a * b / c + a * sqrt(2.0) <= b;
}

bool convex(int* a)
{
	for (int i = 0; i < 8; ++i)
	{
		if (!ccw(a[i], a[(i + 1) % 8], a[(i + 2) % 8]))
			return false;
	}
	return true;
}

int permutation(int* a, int lo, int hi)
{
	int c = 0;
	if (lo + 1 == hi)
		return convex(a);
	for (int i = lo; i < hi; ++i)
	{
		swap(a[lo], a[i]);
		c += permutation(a, lo + 1, hi);
		swap(a[lo], a[i]);
	}
	return c;
}

int main()
{
	int a[8];
	for (int i = 0; i < 8; ++i)
		cin >> a[i];
	cout << permutation(a, 0, 8) << endl;
	return 0;
}