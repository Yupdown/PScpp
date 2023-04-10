#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

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
		return fraction(num * other.den + other.num * den, den * other.den);
	}

	fraction operator-(const fraction& other) const
	{
		return *this + (-other);
	}

	fraction operator*(const fraction& other) const
	{
		return fraction(num * other.num, den * other.den);
	}

	fraction operator/(const fraction& other) const
	{
		return fraction(num * other.den, den * other.num);
	}

	bool operator==(const fraction& other) const
	{
		return num * other.den == other.num * den;
	}

	bool operator!=(const fraction& other) const
	{
		return !(*this == other);
	}

	bool operator==(const int64 other) const
	{
		return num == other * den;
	}

	bool operator!=(const int64 other) const
	{
		return !(*this == other);
	}

	fraction& operator=(const int64 other)
	{
		num = other;
		den = 1LL;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const fraction& v)
	{
		os << v.num << '/' << v.den;
		return os;
	}
};