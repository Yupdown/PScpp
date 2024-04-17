#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

constexpr int64 MOD = 1'000'000'007;
int64 n;

struct fraction
{
public:
    int64 num, den;

public:
    fraction() : num(0ll), den(1ll) {}
    fraction(const int64 numerator) : num(numerator% MOD), den(1ll) {}
    fraction& operator=(const int64 other) { num = other % MOD; den = 1ll; return *this; }
    fraction(const int64 numerator, const int64 denominator) : num(numerator% MOD), den(denominator% MOD)
    {
        if (denominator < 0ll)
        {
            num *= -1ll;
            den *= -1ll;
        }
    }

    fraction operator+() const { return *this; }
    fraction operator-() const { return fraction(-num, den); }
    fraction operator+(const fraction& other) const { return fraction(num * other.den + other.num * den, den * other.den); }
    fraction operator-(const fraction& other) const { return *this + (-other); }
    fraction operator*(const fraction& other) const { return fraction(num * other.num, den * other.den); }
    fraction operator/(const fraction& other) const { return fraction(num * other.den, den * other.num); }
};

template <typename T>
struct matrix
{
public:
    vector<T> value;

public:
    matrix()
    {
        value.resize(n);
    }

    matrix(const matrix& rhs)
    {
        value = rhs.value;
    }

    matrix(matrix&& rhs) noexcept
    {
        value = move(rhs.value);
    }

    matrix operator*(const matrix& rhs) const
    {
        matrix out{};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                out.value[i] = out.value[i] + value[j] * rhs.value[(j - i + n + 1) % n];
        }
        return out;
    }
};

template <typename T>
T pow_logn(const T& x, int64 y)
{
    if (y == 1)
        return x;
    T v{ pow_logn(x, y / 2) };
    if (y & 1)
        return x * v * v;
    return v * v;
}

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

pair<fraction, fraction> points[1000]{};
pair<fraction, fraction> points_p[1000]{};

int main()
{
    FASTIO();

    int64 k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int64 x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    matrix<fraction> m{};
    m.value[0] = fraction(1, 2);
    m.value[1] = fraction(1, 2);

    matrix<fraction> mp{ pow_logn(m, k) };
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            points_p[i].first = points_p[i].first + mp.value[(j - i + n) % n] * points[j].first;
            points_p[i].second = points_p[i].second + mp.value[(j - i + n) % n] * points[j].second;
        }
    }

    fraction sp{};
    fraction sm{};
    for (int i = 0; i < n; ++i)
    {
        sp = sp + points_p[i].second * points_p[(i + 1) % n].first;
        sm = sm + points_p[i].first * points_p[(i + 1) % n].second;
    }

    fraction s{ (sp - sm) / 2 };
    int64 p = s.num;
    if (p < 0)
        p += MOD;
    int64 q = s.den;
    int64 q_inv = mod_inverse(q, MOD);

    cout << (p * q_inv) % MOD;
}