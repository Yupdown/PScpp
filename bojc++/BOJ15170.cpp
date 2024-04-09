#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = __int128;

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
};

struct vector2d { fraction x, y; };

vector2d circumcenter(const vector2d& a, const vector2d& b, const vector2d& c)
{
	fraction ax = a.x - c.x;
	fraction ay = a.y - c.y;
	fraction bx = b.x - c.x;
	fraction by = b.y - c.y;

	fraction asq = ax * ax + ay * ay;
	fraction bsq = bx * bx + by * by;
	fraction ccw = ax * by - ay * bx;

	return vector2d{
		c.x + (by * asq - ay * bsq) / (ccw * 2),
		c.y + (-bx * asq + ax * bsq) / (ccw * 2)
	};
}

fraction sqr_dist(const vector2d& lhs, const vector2d& rhs)
{
	vector2d dv = vector2d{ lhs.x - rhs.x, lhs.y - rhs.y };
	return dv.x * dv.x + dv.y * dv.y;
}

inline int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
	fraction result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	return result > 0 ? 1 : result < 0 ? -1 : 0;
}

vector2d table[100];
char state[100];

bool check(int n, const vector2d& o, const fraction& rr)
{
	for (int l = 0; l < n; ++l)
	{
		if (state[l] == 'I' && sqr_dist(o, table[l]) > rr)
			return false;
		if (state[l] == 'N' && sqr_dist(o, table[l]) < rr)
			return false;
	}
	return true;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y >> state[i];
		table[i] = vector2d{ x, y };
	}

	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		flag |= check(n, table[i], 0);
		for (int j = i + 1; j < n; ++j)
		{
			vector2d p = vector2d{ (table[i].x + table[j].x) / fraction(2), (table[i].y + table[j].y) / fraction(2) };
			fraction rr = sqr_dist(p, table[i]);
			flag |= check(n, p, rr);

			for (int k = j + 1; k < n; ++k)
			{
				if (orientation(table[i], table[j], table[k]) == 0)
					continue;
				vector2d pp = circumcenter(table[i], table[j], table[k]);
				fraction rrp = sqr_dist(pp, table[i]);
				flag |= check(n, pp, rrp);
			}
		}
	}
	cout << (flag ? "No" : "Yes");
}