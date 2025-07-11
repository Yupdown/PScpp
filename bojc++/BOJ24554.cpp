#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
using int64 = long long;

template <typename T>
struct vector2d
{
    T x, y;

    vector2d() : vector2d(0, 0) {}
    vector2d(T x, T y) : x(x), y(y) {}
    vector2d(const vector2d& rhs) : x(rhs.x), y(rhs.y) {}
    template <typename TR>
    vector2d(const vector2d<TR>& rhs) : x(static_cast<T>(rhs.x)), y(static_cast<T>(rhs.y)) {}

    T sqr_magnitude() const { return x * x + y * y; }
    double magnitude() const { return sqrt(sqr_magnitude()); }
    static T dot(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
    static T cross(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }

    vector2d operator+(const vector2d& other) const { return vector2d(x + other.x, y + other.y); }
    vector2d operator-(const vector2d& other) const { return vector2d(x - other.x, y - other.y); }
    vector2d operator+() const { return vector2d(x, y); }
    vector2d operator-() const { return vector2d(-x, -y); }
    vector2d operator*(const T& scalar) const { return vector2d(x * scalar, y * scalar); }
    vector2d operator/(const T& scalar) const { return vector2d(x / scalar, y / scalar); }
    vector2d& operator+=(const vector2d& other) { x += other.x; y += other.y; return *this; }
    vector2d& operator-=(const vector2d& other) { x -= other.x; y -= other.y; return *this; }
    vector2d& operator*=(const T& scalar) { x *= scalar; y *= scalar; return *this; }
    vector2d& operator/=(const T& scalar) { x /= scalar; y /= scalar; return *this; }
    bool operator==(const vector2d& other) const { return x == other.x && y == other.y; }
    bool operator!=(const vector2d& other) const { return x != other.x || y != other.y; }
    bool operator<(const vector2d& other) const { return x < other.x || (x == other.x && y < other.y); }
    bool operator>(const vector2d& other) const { return x > other.x || (x == other.x && y > other.y); }
    bool operator<=(const vector2d& other) const { return x <= other.x && y <= other.y; }
    bool operator>=(const vector2d& other) const { return x >= other.x && y >= other.y; }
};

template <typename T>
vector<vector2d<T>> monotone_chain(vector<vector2d<T>> points)
{
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    size_t n = points.size(), k = 0;
    if (n < 3)
        return points;

    vector<vector2d<T>> out(n * 2);
    for (size_t i = 0; i < n; ++i)
    {
        while (k >= 2 && vector2d<T>::cross(out[k - 1] - out[k - 2], points[i] - out[k - 2]) <= 0)
            --k;
        out[k++] = points[i];
    }
    for (size_t i = n - 1, t = k + 1; i > 0; --i)
    {
        while (k >= t && vector2d<T>::cross(out[k - 1] - out[k - 2], points[i - 1] - out[k - 2]) <= 0)
            --k;
        out[k++] = points[i - 1];
    }

    out.resize(k - 1);
    return out;
}

double get_length(const vector<vector2d<int64>>& ref, double r, double rad, int i, int j, int k)
{
    static double sqrt3 = sqrt(3);

    double rada = rad - M_PI_2;
    double radb = rad + M_PI / 6;
    double radc = rad + M_PI * 5 / 6;

    auto na = vector2d<double>(cos(rada), sin(rada));
    auto nb = vector2d<double>(-na.x / 2 - na.y * sqrt3 / 2, na.x * sqrt3 / 2 - na.y / 2);
    auto nc = vector2d<double>(-na.x / 2 + na.y * sqrt3 / 2, -na.x * sqrt3 / 2 - na.y / 2);

    double a = vector2d<double>::dot(ref[i], na) + r;
    double b = vector2d<double>::dot(ref[j], nb) + r;
    double c = vector2d<double>::dot(ref[k], nc) + r;

    return (a + b + c) * sqrt3 * 2 / 3;
}

int main()
{
    FASTIO();
    PRECISION(40);

    int n, r;
    cin >> n >> r;

    vector<vector2d<int64>> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;

    points = monotone_chain(points);
    n = points.size();

    double mina, maxa;
    // handle degenerate cases
    if (n == 1)
        mina = maxa = r * sqrt(12);
    else if (n == 2)
    {
        double d = (points[0] - points[1]).magnitude();
        mina = r * sqrt(12) + d;
        maxa = (r * 3 + d) * 2 / sqrt(3);
    }
    // handle convex polygon
    else
    {
        mina = 1e+9;
        maxa = 0;

        vector<tuple<double, int, int>> angles(n * 3);
        for (int i = 0; i < n; ++i)
        {
            vector2d<int64> delta = points[i] - points[(i + n - 1) % n];
            double rad = atan2(delta.y, delta.x);
            if (rad < 0)
                rad += M_PI * 2;
            angles[i] = make_tuple(rad, i, 0);
            angles[i + n] = make_tuple(fmod(rad + M_PI * 4 / 3, M_PI * 2), i, 1);
            angles[i + n * 2] = make_tuple(fmod(rad + M_PI * 2 / 3, M_PI * 2), i, 2);
        }

        // sort by angle
        sort(angles.begin(), angles.end());

        // three pointers i, j, k denote the point index of tangents of the triangle
        int i = 0;
        int j = 0;
        int k = 0;
        for (const auto& [rad, index, c] : angles)
        {
            switch (c)
            {
            case 0:
                i = index;
                break;
            case 1:
                j = index;
                break;
            case 2:
                k = index;
                break;
            }
        }
        for (int l = 0; l < n * 3; ++l)
        {
            const auto& [rad0, index0, c0] = angles[l];
            const auto& [rad1, index1, c1] = angles[(l + 1) % (n * 3)];
            switch (c0)
            {
            case 0:
                i = index0;
                break;
            case 1:
                j = index0;
                break;
            case 2:
                k = index0;
                break;
            }

            double a = get_length(points, r, rad0, i, j, k);
            mina = min(mina, a);
            maxa = max(maxa, a);

            double lo = rad0, hi = rad1;

            for (int c = 0; c < 50; ++c)
            {
                double p = (lo * 2 + hi) / 3;
                double q = (lo + hi * 2) / 3;

                double dp = get_length(points, r, p, i, j, k);
                double dq = get_length(points, r, q, i, j, k);

                if (dp > dq)
                    hi = q;
                else
                    lo = p;
            }
            maxa = max(maxa, get_length(points, r, (lo + hi) / 2, i, j, k));
        }
    }
    cout << mina << "\n" << maxa;
}