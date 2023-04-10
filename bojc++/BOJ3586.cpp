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
		if (den == 0LL)
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

struct polynomial
{
	fraction a, b, c, d;
};

polynomial operate(const char oper, const polynomial& lhs, const polynomial& rhs)
{
	polynomial res;
	switch (oper)
	{
	case '+':
		res.a = lhs.a * rhs.d + lhs.b * rhs.c + lhs.c * rhs.b + lhs.d * rhs.a;
		res.b = lhs.b * rhs.d + lhs.d * rhs.b;
		res.c = lhs.c * rhs.d + lhs.d * rhs.c;
		res.d = lhs.d * rhs.d;
		break;
	case '-':
		res.a = lhs.a * rhs.d + lhs.b * rhs.c - lhs.c * rhs.b - lhs.d * rhs.a;
		res.b = lhs.b * rhs.d - lhs.d * rhs.b;
		res.c = lhs.c * rhs.d + lhs.d * rhs.c;
		res.d = lhs.d * rhs.d;
		break;
	case '*':
		res.a = lhs.a * rhs.b + lhs.b * rhs.a;
		res.b = lhs.b * rhs.b;
		res.c = lhs.c * rhs.d + lhs.d * rhs.c;
		res.d = lhs.d * rhs.d;
		break;
	case '/':
		res.a = lhs.a * rhs.d + lhs.b * rhs.c;
		res.b = lhs.b * rhs.d;
		res.c = lhs.c * rhs.b + lhs.d * rhs.a;
		res.d = lhs.d * rhs.b;
		break;
	}
	return res;
}

int solution_equation(const polynomial& p, fraction& x)
{
	if (p.a != 0LL)
	{
		x = -p.b / p.a;
		return 1;
	}
	return p.b != 0LL ? 0 : -1;
}

int main()
{
	char c;
	stack<polynomial> operands;
	vector<fraction> blacklist;

	while (cin >> c)
	{
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		{
			polynomial rhs = operands.top();
			operands.pop();
			polynomial lhs = operands.top();
			operands.pop();
			operands.push(operate(c, lhs, rhs));

			if (c == '/')
			{
				fraction x;
				switch (solution_equation(rhs, x))
				{
				case 1:
					blacklist.push_back(x.reduction());
					break;
				case -1:
					cout << "NONE";
					return 0;
				}
			}
		}
		break;
		case 'X':
			operands.push(polynomial{ 1, 0, 0, 1 });
			break;
		default:
			if (isdigit(c))
				operands.push(polynomial{ 0, c - '0', 0, 1 });
			break;
		}
	};

	fraction x;
	switch (solution_equation(operands.top(), x))
	{
	case 1:
		x = x.reduction();
		if (find(blacklist.begin(), blacklist.end(), x) != blacklist.end())
			cout << "NONE";
		else
			cout << "X = " << x;
		break;
	case 0:
		cout << "NONE";
		break;
	case -1:
		cout << "MULTIPLE";
		break;
	}
}