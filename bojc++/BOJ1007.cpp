#include <iostream>
#include <math.h>

using namespace std;

double dfs(int* x, int* y, bool* v, int len, int now, int cnt)
{
	double result = 1e9 + 7;
	int resultX = 0, resultY = 0;

	if (cnt >= len / 2)
	{
		for (int i = 0; i < len; i++)
		{
			resultX += v[i] ? x[i] : -x[i];
			resultY += v[i] ? y[i] : -y[i];
		}
		result = sqrt((double)resultX * resultX + (double)resultY * resultY);
	}
	else
	{
		for (int i = now; i < len; i++)
		{
			v[i] = true;
			result = min(result, dfs(x, y, v, len, i + 1, cnt + 1));
			v[i] = false;
		}
	}

	return result;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, * x, * y;
		bool* v;
		cin >> n;

		x = new int[n];
		y = new int[n];
		v = new bool[n] { false, };

		for (int j = 0; j < n; j++)
			cin >> x[j] >> y[j];

		printf("%.7lf\n", dfs(x, y, v, n, 0, 0));

		delete[] x;
		delete[] y;
		delete[] v;
	}

	return 0;
}