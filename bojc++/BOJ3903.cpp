#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

template <typename T>
struct vector2d
{
    T x, y;
    vector2d() = default;
    vector2d(T x, T y) : x(x), y(y) {}

    T sqr_magnitude() const { return x * x + y * y; }
    T magnitude() const { return sqrt(sqr_magnitude()); }
    vector2d normalized() const { return *this / magnitude(); }
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
inline int orientation(const vector2d<T>& a, const vector2d<T>& b, const vector2d<T>& c)
{
    T result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : (result < 0 ? -1 : 0);
}

template <typename T>
inline T cross_product(const vector2d<T>& lhs, const vector2d<T>& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

vector2d<double> planes[100][3];

vector2d<double> intersection_point(int lhs, int rhs)
{
    double a11 = planes[lhs][1].x;
    double a12 = -planes[rhs][1].x;
    double a21 = planes[lhs][1].y;
    double a22 = -planes[rhs][1].y;
    double det = a11 * a22 - a12 * a21;
    double t = (a22 / det) * (planes[rhs][2].x - planes[lhs][2].x) - (a12 / det) * (planes[rhs][2].y - planes[lhs][2].y);

    return planes[lhs][2] + planes[lhs][1] * t;
}

bool param_search(int n, double x)
{
    for (int i = 0; i < n; ++i)
        planes[i][2] = vector2d(-planes[i][1].y, planes[i][1].x) * x + planes[i][0];

    deque<int> dq;
    dq.push_back(0);
    dq.push_back(1);
    for (int i = 2; i < n; ++i)
    {
        while (dq.size() >= 2)
        {
            int p1 = *(dq.end() - 2);
            int p2 = *(dq.end() - 1);

            auto v = intersection_point(p1, p2);
            if (cross_product(planes[i][1], v - planes[i][2]) >= 0)
                break;
            dq.pop_back();
        }
        dq.push_back(i);
    }

    while (dq.size() >= 2)
    {
        int p1 = *(dq.end() - 2);
        int p2 = *(dq.end() - 1);

        auto v = intersection_point(p1, p2);
        if (cross_product(planes[dq.front()][1], v - planes[dq.front()][2]) >= 0)
            break;
        dq.pop_back();
    }

    while (dq.size() >= 2)
    {
        int p1 = *(dq.begin());
        int p2 = *(dq.begin() + 1);

        auto v = intersection_point(p1, p2);
        if (cross_product(planes[dq.back()][1], v - planes[dq.back()][2]) >= 0)
            break;
        dq.pop_front();
    }

    return dq.size() >= 3;
}

int main()
{
    FASTIO();
    PRECISION(6);

    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
            cin >> planes[i][0].x >> planes[i][0].y;
        for (int i = 0; i < n; ++i)
            planes[i][1] = (planes[(i + 1) % n][0] - planes[i][0]).normalized();
        double x = 0;
        for (double dx = 1e+4; dx > 1e-10; dx *= 0.5)
        {
            if (param_search(n, x + dx))
                x += dx;
        }
        cout << x << "\n";
    }
}