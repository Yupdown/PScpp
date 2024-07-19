#include <bits/stdc++.h>

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
    T magnitude() const { return sqrt(sqr_magnitude()); }
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
    size_t n = points.size(), k = 0;
    if (n <= 3)
        return points;

    sort(points.begin(), points.end());

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

template <typename T>
pair<vector2d<T>, vector2d<T>> rotating_calipers(vector<vector2d<T>> points)
{
    pair<vector2d<T>, vector2d<T>> out;
    int n = points.size();
    T magnitude_max = 0;

    for (int i = 0, j = 1; i < n; i++)
    {
        int iNext = (i + 1) % n;
        vector2d<T> iVector = points[iNext] - points[i];
        do
        {
            int jNext = (j + 1) % n;
            vector2d<T> jVector = points[jNext] - points[j];
            if (vector2d<T>::cross(iVector, jVector) > 0)
                j = jNext;
            else
                break;
        } while (true);

        T magnitude = (points[i] - points[j]).sqr_magnitude();
        if (magnitude > magnitude_max)
        {
            out = make_pair(points[i], points[j]);
            magnitude_max = magnitude;
        }
    }

    return out;
}