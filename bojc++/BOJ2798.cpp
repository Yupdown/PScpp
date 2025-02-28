#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, m, values[100], vmax = 0;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> values[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				int v = values[i] + values[j] + values[k];
				if (v <= m)
					vmax = max(vmax, v);
			}
		}
	}

	cout << vmax << endl;
	return 0;
}