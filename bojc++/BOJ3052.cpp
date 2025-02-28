#include <iostream>

using namespace std;

int main()
{
	int result = 0;
	int array[42] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		int value;
		cin >> value;
		array[value % 42]++;
	}

	for (int i = 0; i < 42; i++)
		result += array[i] > 0 ? 1 : 0;

	cout << result << endl;
	return 0;
}