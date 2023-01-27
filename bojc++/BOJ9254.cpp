#include <iostream>

using namespace std;
typedef pair<double, double> element;

element matrix[500][500];

void print(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << matrix[i][j].first << '\t';
		cout << "|\t";
		for (int j = 0; j < n; ++j)
			cout << matrix[i][j].second << '\t';
		cout << '\n';
	}
	cout << '\n';
}

int main2()
{
	cout << fixed;
	cout.precision(2);

	int n;
	cin >> n;

	int m[3][3];

	while (true)
	{

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> m[i][j];
		}

		int a = m[1][1] * m[2][2] - m[2][1] * m[1][2];
		int b = m[1][2] * m[2][0] - m[2][2] * m[1][0];
		int c = m[1][0] * m[2][1] - m[2][0] * m[1][1];

		cout << m[0][0] * a + m[0][1] * b + m[0][2] * c << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j].first;
			matrix[i][j].second = i == j;
		}

	}

	for (int i = 0; i < n; i++)
	{
		if (matrix[i][i].first == 0.0)
		{
			int j = i;
			while (++j < n)
			{
				if (matrix[j][i].first != 0.0)
					break;
			}

			if (j == n)
			{
				cout << "no inverse" << endl;
				return 0;
			}

			for (int k = 0; k < n; k++)
			{
				element temp = matrix[i][k];
				matrix[i][k] = matrix[j][k];
				matrix[j][k] = temp;
			}
		}

		double factor0 = matrix[i][i].first;

		for (int j = 0; j < n; j++)
		{
			matrix[i][j].first /= factor0;
			matrix[i][j].second /= factor0;
		}

		for (int j = i + 1; j < n; j++)
		{
			double factor1 = matrix[j][i].first;

			for (int k = 0; k < n; k++)
			{
				matrix[j][k].first -= matrix[i][k].first * factor1;
				matrix[j][k].second -= matrix[i][k].second * factor1;
			}
		}

		print(n);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			double factor2 = matrix[j][i].first;

			for (int k = 0; k < n; k++)
			{
				matrix[j][k].first -= matrix[i][k].first * factor2;
				matrix[j][k].second -= matrix[i][k].second * factor2;
			}
		}

		print(n);
	}

	for (int i = 0; i < n * n; i++)
		cout << matrix[i / n][i % n].second << (i % n < n - 1 ? ' ' : '\n');

	return 0;
}