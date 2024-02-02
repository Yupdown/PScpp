#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

struct fraction
{
private:
	int64 num, den;

public:
	fraction() : num(0ll), den(1ll) {}
	fraction(const int64 numerator) : num(numerator), den(1ll) {}
	fraction(const int64 numerator, const int64 denominator) : num(numerator), den(denominator)
	{
		if (denominator < 0ll)
		{
			num *= -1ll;
			den *= -1ll;
		}
	}

	fraction reduction() const
	{
		if (num == 0ll)
			return fraction(0ll); 
		int64 a = abs(num);
		int64 b = den; 
		while (b != 0ll)
		{
			int64 temp = a % b;
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
	fraction& operator=(const int64 other) { num = other; den = 1ll; return *this; } 
	explicit operator double() const { return static_cast<double>(num) / den; }
	friend ostream& operator<<(ostream& os, const fraction& v) { os << v.num << '/' << v.den; return os; }
};