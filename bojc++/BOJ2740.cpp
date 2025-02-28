#include <iostream>
#define SIZE 100

using namespace std;

int main()
{
	int matrix[SIZE][SIZE][2];
	int n, m, k;

	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> matrix[i / m][i % m][0];

	cin >> m >> k;
	for (int i = 0; i < m * k; i++)
		cin >> matrix[i / k][i % k][1];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int r = 0;
			for (int l = 0; l < m; l++)
				r += matrix[i][l][0] * matrix[l][j][1];
			cout << r << ' ';
		}
		cout << endl;
	}

	return 0;
}