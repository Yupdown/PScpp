#include <iostream>
#define SIZE 5

using namespace std;

void multiply(int n, int dst[SIZE][SIZE], int src[SIZE][SIZE])
{
	int** temp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = new int[n] { 0 };
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				temp[i][j] += dst[i][k] * src[k][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dst[i][j] = temp[i][j] % 1000;
		delete[] temp[i];
	}
	delete[] temp;
}

void function(int n, long long b, int matrixA[SIZE][SIZE], int matrixB[SIZE][SIZE])
{
	if (b > 1)
	{
		if (b % 2)
		{
			function(n, b - 1, matrixA, matrixB);
			multiply(n, matrixA, matrixB);
		}
		else
		{
			function(n, b / 2, matrixA, matrixB);
			multiply(n, matrixA, matrixA);
		}
	}
}

int main()
{
	int matrixA[SIZE][SIZE];
	int matrixB[SIZE][SIZE];

	int n;
	long long b;
	cin >> n >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;

			matrixA[i][j] = input % 1000;
			matrixB[i][j] = input % 1000;
		}
	}

	function(n, b, matrixA, matrixB);

	for (int i = 0; i < n * n; i++)
		cout << matrixA[i / n][i % n] << (i % n < n - 1 ? ' ' : '\n');

	return 0;
}