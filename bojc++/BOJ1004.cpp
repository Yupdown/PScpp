#include <iostream>

using namespace std;

int main()
{
	int t;
	int x1, y1, x2, y2;
	int n;
	int cx, cy, r;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		int result = 0;

		for (int j = 0; j < n; j++)
		{
			cin >> cx >> cy >> r;

			int x1d = cx - x1;
			int y1d = cy - y1;
			int x2d = cx - x2;
			int y2d = cy - y2;

			if ((x1d * x1d + y1d * y1d < r * r) ^ (x2d * x2d + y2d * y2d < r * r))
				result++;
		}

		cout << result << '\n';
	}
}