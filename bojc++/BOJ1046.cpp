#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

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

const fraction& (*min_fraction)(const fraction&, const fraction&) = min<fraction>;
const fraction& (*max_fraction)(const fraction&, const fraction&) = max<fraction>;

char table[64][64];
bool vertical[64][64];
bool horizontal[64][64];

vector<pair<fraction, int>> direction_pre;
vector<pair<fraction, int>> direction_post;
vector<pair<fraction, fraction>> intersection;

int main()
{
	FASTIO();
	PRECISION(14);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	int size_wall = 0;
	fraction lx, ly;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			switch (table[i][j])
			{
			case '#':
				size_wall += 1;
				break;
			case '*':
				table[i][j] = '.';
				lx = fraction(j * 2 + 1, 2);
				ly = fraction(i * 2 + 1, 2);
				break;
			}
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (i == 0 || i == n)
				horizontal[i][j] = true;
			else
				horizontal[i][j] = table[i - 1][j] != table[i][j];
			if (j == 0 || j == m)
				vertical[j][i] = true;
			else
				vertical[j][i] = table[i][j - 1] != table[i][j];
		}
	}
	
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
			direction_pre.push_back(make_pair((ly - i) / (lx - j), lx < j ? 1 : -1));
	}

	sort(direction_pre.begin(), direction_pre.end(), [](const pair<fraction, int>& lhs, const pair<fraction, int>& rhs) {
			if (lhs.second != rhs.second)
				return lhs.second > rhs.second;
			return lhs.first < rhs.first;
		});

	for (auto& direction : direction_pre)
	{
		bool flag = direction_post.empty();
		if (!flag)
		{
			auto& p = direction_post.back();
			flag = p.first != direction.first || p.second != direction.second;
		}
		if (flag)
		{
			fraction f = direction.second > 0 ? m : 0;
			direction_post.push_back(direction);
			intersection.push_back(make_pair(f, f));
		}
	}

	int dnum = direction_post.size();
	for (int i = 0; i < dnum; ++i)
	{
		auto& direction = direction_post[i];
		auto& modify_callback = (direction.second > 0 ? min_fraction : max_fraction);

		for (int x = 0; x <= m; ++x)
		{
			if ((lx - x) * direction.second > 0)
				continue;
			fraction cy = direction.first * -(lx - x) + ly;
			for (int y = 0; y < n; ++y)
			{
				if (!vertical[x][y])
					continue;
				bool flag0 = false;
				bool flag1 = false;
				if (cy == y)
					flag0 = true;
				else if (cy == y + 1)
					flag1 = true;
				else if (cy > y && cy < y + 1)
				{
					flag0 = true;
					flag1 = true;
				}
				if (direction.second > 0)
					swap(flag0, flag1);
				if (flag0)
					intersection[i].first = modify_callback(intersection[i].first, x);
				if (flag1)
					intersection[i].second = modify_callback(intersection[i].second, x);
			}
		}

		for (int y = 0; y <= n; ++y)
		{
			if ((ly - y) * direction.first * direction.second > 0)
				continue;
			fraction cx = -(ly - y) / direction.first + lx;
			for (int x = 0; x < m; ++x)
			{
				if (!horizontal[y][x])
					continue;
				bool flag0 = false;
				bool flag1 = false;
				if (cx == x)
					flag0 = true;
				else if (cx == x + 1)
					flag1 = true;
				else if (cx > x && cx < x + 1)
				{
					flag0 = true;
					flag1 = true;
				}
				if (direction.first * direction.second < 0)
					swap(flag0, flag1);
				if (flag0)
					intersection[i].first = modify_callback(intersection[i].first, cx);
				if (flag1)
					intersection[i].second = modify_callback(intersection[i].second, cx);
			}
		}
	}

	double size_light = 0.0;
	for (int i = 0; i < dnum; ++i)
	{
		double ax = static_cast<double>(lx);
		double ay = static_cast<double>(ly);
		double bx = static_cast<double>(intersection[i].second);
		double by = static_cast<double>(direction_post[i].first * (intersection[i].second - lx) + ly);
		double cx = static_cast<double>(intersection[(i + 1) % dnum].first);
		double cy = static_cast<double>(direction_post[(i + 1) % dnum].first * (intersection[(i + 1) % dnum].first - lx) + ly);
		size_light += (ax * by + bx * cy + cx * ay - bx * ay - cx * by - ax * cy) * 0.5;
	}

	cout << m * n - size_wall - size_light;
}