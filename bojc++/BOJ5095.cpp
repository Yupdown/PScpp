#include <iostream>
#define SIZE 100

using namespace std;
typedef long long int64;

void multiply(int n, int m, int64 dst[SIZE][SIZE], int64 src[SIZE][SIZE])
{
	int64** temp = new int64 * [n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = new int64[n]{ 0 };
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				temp[i][j] += dst[i][k] * src[k][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dst[i][j] = temp[i][j] % m;
		delete[] temp[i];
	}
	delete[] temp;
}

void function(int n, int m, int p, int64 matrixA[SIZE][SIZE], int64 matrixB[SIZE][SIZE])
{
	if (p > 1)
	{
		if (p % 2)
		{
			function(n, m, p - 1, matrixA, matrixB);
			multiply(n, m, matrixA, matrixB);
		}
		else
		{
			function(n, m, p >> 1, matrixA, matrixB);
			multiply(n, m, matrixA, matrixA);
		}
	}
}

int main()
{
	int64 matrixA[SIZE][SIZE];
	int64 matrixB[SIZE][SIZE];

	while (true)
	{
		int n, m, p;
		cin >> n >> m >> p;
		if (!n && !m && !p)
			break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int64 input;
				cin >> input;

				matrixA[i][j] = input;
				matrixB[i][j] = input;
			}
		}

		function(n, m, p, matrixA, matrixB);

		for (int i = 0; i < n * n; i++)
			cout << matrixA[i / n][i % n] << (i % n < n - 1 ? ' ' : '\n');
		cout << endl;
	}

	return 0;
}