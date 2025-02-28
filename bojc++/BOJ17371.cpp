#include <iostream>

using namespace std;

int sqr_magnitude(int x, int y)
{
	return x * x + y * y;
}

int main()
{
	int points[1000][2], n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> points[i][0] >> points[i][1];

	int minDist = 0, minIndex = 0;
	for (int i = 0; i < n; ++i)
	{
		int far = 0;
		for (int j = 0; j < n; ++j)
		{
			int sqrDist = sqr_magnitude(points[i][0] - points[j][0], points[i][1] - points[j][1]);
			far = far > sqrDist ? far : sqrDist;
		}

		if (!(i > 0) || far < minDist)
		{
			minDist = far;
			minIndex = i;
		}
	}

	cout << points[minIndex][0] << ' ' << points[minIndex][1] << endl;
	return 0;
}