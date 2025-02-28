#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* buildings = new int[n];

	for (int i = 0; i < n; i++)
		cin >> buildings[i];

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int count = i > 0 && i < n - 1 ? 2 : (n > 1 ? 1 : 0);

		for (int j = i - 2, h = i - 1; j >= 0; j--)
		{
			if ((double)buildings[j] > buildings[i] + (double)(buildings[h] - buildings[i]) * (i - j) / (i - h))
			{
				count++;
				h = j;
			}
		}

		for (int j = i + 2, h = i + 1; j < n; j++)
		{
			if ((double)buildings[j] > buildings[i] + (double)(buildings[h] - buildings[i]) * (i - j) / (i - h))
			{
				count++;
				h = j;
			}
		}

		result = count > result ? count : result;
	}

	cout << result << endl;

	delete[] buildings;

	return 0;
}