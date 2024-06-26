#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

template <typename T>
struct matrix
{
public:
	matrix() = default;
	matrix(size_t rows, size_t columns) : rows(rows), columns(columns)
	{
		m.resize(rows);
		for (int i = 0; i < rows; ++i)
			m[i].resize(columns);
	}

	matrix(const matrix& rhs) = default;
	matrix& operator=(const matrix& rhs) = default;

	static matrix One(size_t length)
	{
		matrix ret(length, length);
		for (int i = 0; i < length * length; ++i)
			ret.m[i / length][i % length] = i / length == i % length;
		return ret;
	}

	matrix operator+(const matrix& rhs) const
	{
		matrix ret(rows, columns);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
				ret.m[i][j] = m[i][j] + rhs.m[i][j];
		}
		return ret;
	}

	matrix operator-() const
	{
		matrix ret(rows, columns);
		for (int i = 0; i < rows * columns; ++i)
			ret.m[i / columns][i % columns] = -m[i / columns][i % columns];
		return ret;
	}

	matrix operator-(const matrix& rhs) const
	{
		return *this + (-rhs);
	}

	matrix operator*(const T& rhs) const
	{
		matrix ret(rows, columns);
		for (int i = 0; i < rows * columns; ++i)
			ret.m[i / columns][i % columns] = m[i / columns][i % columns] * rhs;
		return ret;
	}

	matrix operator%(const T& rhs) const
	{
		matrix ret(rows, columns);
		for (int i = 0; i < rows * columns; ++i)
			ret.m[i / columns][i % columns] = m[i / columns][i % columns] % rhs;
		return ret;
	}

	matrix operator*(const matrix& rhs) const
	{
		matrix ret(rows, columns);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				ret.m[i][j] = 0;
				for (int k = 0; k < rows; ++k)
					ret.m[i][j] += m[i][k] * rhs.m[k][j];
			}
		}
		return ret;
	}

	vector<T>& operator[](size_t index)
	{
		return m[index];
	}

public:
	size_t rows = 0;
	size_t columns = 0;
	vector<vector<T>> m;
};

constexpr int MODULO = 1000;

matrix<int> apowi[64];
matrix<int> sigapowi[64];

int main()
{
	FASTIO();

	long long n, b;
	cin >> n >> b;

	matrix<int> mat(n, n);

	for (int i = 0; i < n * n; ++i)
		cin >> mat[i / n][i % n];

	apowi[1] = mat;
	sigapowi[1] = mat;

	for (int i = 2; i < 64; ++i)
	{
		apowi[i] = apowi[i - 1] * apowi[i - 1] % MODULO;
		sigapowi[i] = (sigapowi[i - 1] + apowi[i - 1] * sigapowi[i - 1]) % MODULO;
	}

	matrix<int> ret(n, n);
	for (int i = 0; b >> i > 0; ++i)
	{
		if (b >> i & 1)
		{
			ret = apowi[i + 1] * ret % MODULO;
			ret = (ret + sigapowi[i + 1]) % MODULO;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << ret[i][j] << ' ';
		cout << '\n';
	}
}