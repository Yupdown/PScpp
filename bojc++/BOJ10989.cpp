#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int* array = new int[10000] { 0 };
	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d", &input);
		array[input - 1]++;
	}

	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < array[i]; j++)
			printf("%d\n", i + 1);
	}

	return 0;
}