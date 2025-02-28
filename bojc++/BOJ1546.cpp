#include <iostream>

using namespace std;

int main()
{
	int n, max = 0, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;

		max = value > max ? value : max;
		sum += value;
	}

	cout << (double)(sum * 100) / (max * n) << endl;

	return 0;
}