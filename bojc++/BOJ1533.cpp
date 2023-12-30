#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define LENGTH 50
#define MODULO 1'000'003

using namespace std;
typedef long long int64;

int64 matrix_in[LENGTH][LENGTH];
int64 matrix_out[LENGTH][LENGTH];

void matrix_multiply(int64 dst[LENGTH][LENGTH], const int64 src[LENGTH][LENGTH])
{
	static int64 temp[LENGTH][LENGTH];

	for (int i = 0; i < LENGTH; ++i)
	{
		for (int j = 0; j < LENGTH; ++j)
		{
			temp[i][j] = 0;
			for (int k = 0; k < LENGTH; ++k)
				temp[i][j] += dst[i][k] * src[k][j];
		}
	}

	for (int i = 0; i < LENGTH; ++i)
	{
		for (int j = 0; j < LENGTH; ++j)
			dst[i][j] = temp[i][j] % MODULO;
	}
}

void matrix_power(int64 dst[LENGTH][LENGTH], const int64 src[LENGTH][LENGTH], int y)
{
	if (y <= 1)
		return;
	else if (y & 1)
	{
		matrix_power(dst, src, y - 1);
		matrix_multiply(dst, src);
	}
	else
	{
		matrix_power(dst, src, y / 2);
		matrix_multiply(dst, dst);
	}
}

int main()
{
	FASTIO();

	char buffer[16];
	int n, s, e, t;
	cin >> n >> s >> e >> t;
	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;

		int sp = i * 4 + 10;
		matrix_in[i][sp] = 1;
		for (int j = 0; j < 3; ++j)
			matrix_in[sp + j][sp + j + 1] = 1;

		for (int j = 0; j < n; ++j)
		{
			int m = buffer[j] - '0';
			if (m == 1)
				matrix_in[i][j] = 1;
			else if (m > 1)
				matrix_in[sp + m - 2][j] = 1;
		}
	}

	memcpy(matrix_out, matrix_in, sizeof(matrix_out));
	matrix_power(matrix_out, matrix_in, t);

	cout << matrix_out[s - 1][e - 1];
}