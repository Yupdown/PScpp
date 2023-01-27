#include <iostream>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

struct matrix_2x2
{
public:
	int64 m00, m01, m10, m11;

	matrix_2x2 operator*(const matrix_2x2& other)
	{
		return matrix_2x2
		{
			m00 * other.m00 + m01 * other.m10,
			m00 * other.m01 + m01 * other.m11,
			m10 * other.m00 + m11 * other.m10,
			m10 * other.m01 + m11 * other.m11
		};
	}

	matrix_2x2 operator%(const int64& mod)
	{
		return matrix_2x2
		{
			m00 % mod,
			m01 % mod,
			m10 % mod,
			m11 % mod
		};
	}
};

matrix_2x2 one = matrix_2x2{ 0, 1, 1, 1 };
int64 modulo = 1000000;

matrix_2x2 function(int64 n)
{
	if (n == 1)
		return one;

	matrix_2x2 mat;
	if (n % 2)
		mat = function(n - 1) * one;
	else
	{
		mat = function(n / 2);
		mat = mat * mat;
	}

	return mat % modulo;
}

int main()
{
	FASTIO();

	int64 n;
	cin >> n;
	cout << (n > 1 ? function(n - 1).m11 : 1) << endl;
	return 0;
}