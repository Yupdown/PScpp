#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
using int64 = long long;

struct fraction
{
private:
	int64 num, den;

public:
	fraction()
	{
		num = 0LL;
		den = 1LL;
	}

	fraction(const int64 numerator)
	{
		num = numerator;
		den = 1LL;
	}

	fraction(const int64 numerator, const int64 denominator)
	{
		num = numerator;
		den = denominator;

		if (denominator < 0LL)
		{
			num *= -1LL;
			den *= -1LL;
		}
	}

	fraction reduction() const
	{
		if (num == 0LL)
			return fraction(0LL);
		
		int64 a = abs(num);
		int64 b = den;

		while (b != 0LL)
		{
			int64 temp = a % b;
			a = b;
			b = temp;
		}

		return fraction(num / a, den / a);
	}

	fraction operator+() const
	{
		return *this;
	}

	fraction operator-() const
	{
		return fraction(-num, den);
	}

	fraction operator+(const fraction& other) const
	{
		return fraction(num * other.den + other.num * den, den * other.den).reduction();
	}

	fraction operator-(const fraction& other) const
	{
		return *this + (-other);
	}

	fraction operator*(const fraction& other) const
	{
		return fraction(num * other.num, den * other.den).reduction();
	}

	fraction operator/(const fraction& other) const
	{
		return fraction(num * other.den, den * other.num).reduction();
	}

	bool operator==(const fraction& other) const
	{
		return num * other.den == other.num * den;
	}

	bool operator!=(const fraction& other) const
	{
		return !(*this == other);
	}

	bool operator<(const fraction& other) const
	{
		return num * other.den < other.num * den;
	}

	bool operator>(const fraction& other) const
	{
		return num * other.den > other.num * den;
	}

	bool operator<=(const fraction& other) const
	{
		return !(*this > other);
	}

	bool operator>=(const fraction& other) const
	{
		return !(*this < other);
	}

	fraction& operator=(const int64 other)
	{
		num = other;
		den = 1LL;
		return *this;
	}

	explicit operator double() const
	{
		return static_cast<double>(num) / den;
	}

	friend ostream& operator<<(ostream& os, const fraction& v)
	{
		os << v.num << '/' << v.den;
		return os;
	}
};

struct rgb
{
	int64 r, g, b;

	rgb operator-() const
	{
		return { -r, -g, -b };
	}

	rgb operator+(const rgb& v) const
	{
		return { r + v.r, g + v.g, b + v.b };
	}

	rgb operator-(const rgb& v) const
	{
		return *this + (-v);
	}

	rgb operator*(const int64 s) const
	{
		return { r * s, g * s, b * s };
	}
};
using split_callback = function<void(const vector<rgb>&, const vector<rgb>&)>;

inline int64 dot_product(const rgb& lhs, const rgb& rhs)
{
	return lhs.r * rhs.r + lhs.g * rhs.g + lhs.b * rhs.b;
}

inline rgb cross_product(const rgb& lhs, const rgb& rhs)
{
	return { lhs.g * rhs.b - lhs.b * rhs.g, lhs.b * rhs.r - lhs.r * rhs.b, lhs.r * rhs.g - lhs.g * rhs.r };
}

fraction get_cvalue(const vector<rgb>& v)
{
	int64 ret = 0;
	int64 n = v.size();
	rgb sum = { 0, 0, 0 };
	if (n <= 1)
		return 0;
	for (int i = 0; i < n; ++i)
		sum = sum + v[i];
	for (int i = 0; i < n; ++i)
	{
		rgb del = v[i] * n - sum;
		ret += del.r * del.r + del.g * del.g + del.b * del.b;
	}
	return fraction(ret, n * n);
}

void split_method1(const vector<rgb>& v, split_callback callback)
{
	int n = v.size();
	vector<rgb> lhs, rhs;

	for (int bit = 0; bit < 1 << n; ++bit)
	{
		lhs.clear();
		rhs.clear();

		for (int i = 0; i < n; ++i)
		{
			if (1 << i & bit)
				lhs.push_back(v[i]);
			else
				rhs.push_back(v[i]);
		}
		callback(lhs, rhs);
	}
}

void split_method2(const vector<rgb>& v, split_callback callback)
{
	int n = v.size();
	vector<rgb> lhs, rhs, pln;
	pln.resize(3);

	for (int i = 0; i < n; ++i)
	{
		pln[0] = v[i];
		for (int j = i + 1; j < n; ++j)
		{
			pln[1] = v[j];
			for (int k = j + 1; k < n; ++k)
			{
				pln[2] = v[k];

				lhs.clear();
				rhs.clear();

				rgb tn = cross_product(pln[1] - pln[0], pln[2] - pln[0]);
				for (int l = 0; l < n; ++l)
				{
					if (l == i || l == j || l == k)
						continue;
					if (dot_product(tn, v[l] - pln[0]) > 0)
						lhs.push_back(v[l]);
					else
						rhs.push_back(v[l]);
				}

				split_method1(pln, [&](const vector<rgb>& pln_lhs, const vector<rgb>& pln_rhs) {
					lhs.insert(lhs.end(), pln_lhs.begin(), pln_lhs.end());
					rhs.insert(rhs.end(), pln_rhs.begin(), pln_rhs.end());
					callback(lhs, rhs);
					lhs.resize(lhs.size() - pln_lhs.size());
					rhs.resize(rhs.size() - pln_rhs.size());
					});
			}
		}
	}
}

vector<rgb> col;

int main()
{
	FASTIO();
	PRECISION(6);

	int n, k;
	cin >> n >> k;

	col.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> col[i].r >> col[i].g >> col[i].b;

	if (k == 1)
		cout << static_cast<double>(get_cvalue(col));
	else
	{
		double ret = numeric_limits<double>::infinity();
		auto callback = [&ret](const vector<rgb>& lhs, const vector<rgb>& rhs) {
			ret = min(ret, static_cast<double>(get_cvalue(lhs) + get_cvalue(rhs)));
			};
		(n < 8 ? split_method1 : split_method2)(col, callback);
		cout << ret;
	}
}