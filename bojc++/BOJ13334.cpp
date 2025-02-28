#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, d, c = 0, r = 0;
	int pMin[100000];
	int pMax[100000];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pMin[i] = min(a, b);
		pMax[i] = max(a, b);
	}
	cin >> d;

	for (int i = 0, j = 0, m = n; i < m; i++)
	{
		pMin[j] = pMin[i];
		pMax[j] = pMax[i];
		if (pMax[i] - pMin[i] > d)
			n--;
		else
			j++;
	}

	sort(pMin, pMin + n);
	sort(pMax, pMax + n);

	for (int i = 0, j = 0; i < n; i++)
	{
		while (j < n && pMax[j] <= pMin[i] + d)
			j++, c++;
		r = max(r, c);
		c = max(c - 1, 0);
	}

	cout << r << endl;
	return 0;
}