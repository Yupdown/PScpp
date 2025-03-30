#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

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

using vector2di = vector2d<long long>;

int main()
{
    FASTIO();
    PRECISION(10);

    int n;
    cin >> n;
    vector<vector2di> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;
    vector<vector2di> hull_points = monotone_chain(points);
    if (hull_points.size() == 1)
        cout << 0;
    else if (hull_points.size() == 2)
        cout << (hull_points[1] - hull_points[0]).magnitude() * 2;
    else
    {
        double ret = 1e+9;
        n = hull_points.size();
        for (int i = 0, j = 0, k = 0, l = 0; i < n; ++i)
        {
            vector2di iv = hull_points[(i + 1) % n] - hull_points[i];
            while (vector2di::dot(iv, hull_points[(j + 1) % n] - hull_points[j]) >= 0)
                j = (j + 1) % n;
            while (vector2di::cross(iv, hull_points[(k + 1) % n] - hull_points[k]) >= 0)
            {
                if (l == k)
                    l = (l + 1) % n;
                k = (k + 1) % n;
            }
            while (vector2di::dot(iv, hull_points[(l + 1) % n] - hull_points[l]) <= 0)
                l = (l + 1) % n;
            ret = min(ret, (vector2di::cross(iv, hull_points[k] - hull_points[i]) + vector2di::cross(vector2di(-iv.y, iv.x), hull_points[l] - hull_points[j])) / iv.magnitude());
        }
        cout << ret * 2;
    }
}