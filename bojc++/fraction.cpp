#include <bits/stdc++.h>

template <typename T>
struct fraction
{
public:
	T num, den;

	fraction() : num(0), den(1) {}
	fraction(const T numerator) : num(numerator), den(1) {}
	fraction(const T numerator, const T denominator) : num(numerator), den(denominator)
	{
		if (denominator < 0)
		{
			num *= -1;
			den *= -1;
		}
	}

	fraction reduction() const
	{
		if (num == 0)
			return fraction(0); 
		T a = abs(num);
		T b = den; 
		while (b != 0)
		{
			T temp = a % b;
			a = b;
			b = temp;
		} 
		return fraction(num / a, den / a);
	}

	fraction operator+() const { return *this; }
	fraction operator-() const { return fraction(-num, den); }
	fraction operator+(const fraction& other) const { return fraction(num * other.den + other.num * den, den * other.den).reduction(); }
	fraction operator-(const fraction& other) const { return *this + (-other); }
	fraction operator*(const fraction& other) const { return fraction(num * other.num, den * other.den).reduction(); }
	fraction operator/(const fraction& other) const { return fraction(num * other.den, den * other.num).reduction(); }
	bool operator==(const fraction& other) const { return num * other.den == other.num * den; }
	bool operator!=(const fraction& other) const { return !(*this == other); }
	bool operator<(const fraction& other) const { return num * other.den < other.num * den; }
	bool operator>(const fraction& other) const { return num * other.den > other.num * den; }
	bool operator<=(const fraction& other) const { return !(*this > other); }
	bool operator>=(const fraction& other) const { return !(*this < other); }
	fraction& operator=(const T other) { num = other; den = 1; return *this; } 
	explicit operator double() const { return static_cast<double>(num) / den; }
};