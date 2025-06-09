#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
constexpr int64 MOD = 1000000007;

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
		return fraction(num % MOD, den % MOD);
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

int64 mod_inverse(int64 a, int64 m) {
    int64 m0 = m, t, q;
    int64 x0 = 0, x1 = 1;

    while (a > 1)
    {
        if (m == 0)
            return -1;

        q = a / m;
        t = m;

        m = a % m, a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

fraction<int64> solution(fraction<int64> real, fraction<int64> imag, int64 power)
{
	fraction<int64> rreal(1);
	fraction<int64> rimag(0);
	while (power > 0)
	{
		if (power & 1)
			tie(rreal, rimag) = make_tuple(rreal * real - rimag * imag, rreal * imag + rimag * real);
		tie(real, imag) = make_tuple(real * real - imag * imag, real * imag + imag * real);
		power >>= 1;
	}
	return rreal;
}

int main()
{
    int64 a, b, n;
    cin >> a >> b >> n;

	fraction<int64> real(a * a - b * b, a * a + b * b);
	fraction<int64> imag(2 * a * b, a * a + b * b);
	real.num %= MOD;
	real.den %= MOD;
	imag.num %= MOD;
	imag.den %= MOD;

	fraction<int64> ret = -solution(real, imag, n + 1);
	cout << (ret.num + MOD) % MOD * mod_inverse(ret.den, MOD) % MOD;
}