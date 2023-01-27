#include <iostream>

using namespace std;

double matrix[6][7];

int main()
{
	cout << fixed;
	cout.precision(2);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
			cin >> matrix[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		double factorA = matrix[i][i];

		for (int j = 0; j < n + 1; j++)
			matrix[i][j] /= factorA;

		for (int j = i + 1; j < n; j++)
		{
			double factorB = matrix[j][i];

			for (int k = 0; k < n + 1; k++)
				matrix[j][k] -= matrix[i][k] * factorB;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			double factor = matrix[j][i];

			for (int k = 0; k < n + 1; k++)
				matrix[j][k] -= matrix[i][k] * factor;
		}
	}

	for (int i = 0; i < n; i++)
		cout << matrix[i][n] << ' ';
	cout << endl;

	return 0;
}