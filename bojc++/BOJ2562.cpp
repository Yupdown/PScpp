#include <iostream>

using namespace std;

int main()
{
	int max = 0, maxIndex = 0;

	for (int i = 0; i < 9; i++)
	{
		int value;
		cin >> value;

		if (value > max)
		{
			max = value;
			maxIndex = i;
		}
	}

	cout << max << endl << maxIndex + 1 << endl;

	return 0;
}