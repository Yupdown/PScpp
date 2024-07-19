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
inline int orientation(const vector2d<T>& a, const vector2d<T>& b, const vector2d<T>& c)
{
    T result = vector2d<T>::cross(b - a, c - a);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

template <typename T>
bool line_intersection(const vector2d<T>& p1, const vector2d<T>& p2, const vector2d<T>& p3, const vector2d<T>& p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if ((!o1 && !o2) || (!o3 && !o4))
    {
        T x1, x2, x3, x4;
        if (p1.x == p2.x && p3.x == p4.x && p1.x == p3.x)
        {
            x1 = p1.y;
            x2 = p2.y;
            x3 = p3.y;
            x4 = p4.y;
        }
        else
        {
            x1 = p1.x;
            x2 = p2.x;
            x3 = p3.x;
            x4 = p4.x;
        }
        return max(abs(min(x1, x2) - max(x3, x4)), abs(min(x3, x4) - max(x1, x2))) < abs(x1 - x2) + abs(x3 - x4);
    }
    return (o1 * o2 < 0) && (o3 * o4 < 0);
}

template <typename T>
vector2d<T> intersection_point(const vector2d<T>& p1, const vector2d<T>& p2, const vector2d<T>& p3, const vector2d<T>& p4)
{
    T a11 = p2.x - p1.x;
    T a12 = p3.x - p4.x;
    T a21 = p2.y - p1.y;
    T a22 = p3.y - p4.y;
    T det = a11 * a22 - a12 * a21;
    T t = (a22 / det) * (p3.x - p1.x) - (a12 / det) * (p3.y - p1.y);
    return p1 + (p2 - p1) * t;
}

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

using vector2di = vector2d<int>;
using vector2df = vector2d<double>;

vector2di points[2][100];
vector<vector2df> vertices;

int main()
{
	FASTIO();
	PRECISION(15);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> points[0][i].x >> points[0][i].y;
    for (int i = 0; i < m; ++i)
        cin >> points[1][i].x >> points[1][i].y;

    for (int i = 0; i < n; ++i)
    {
        bool flag = true;
        for (int j = 0; j < m && flag; ++j)
            flag &= orientation(points[1][j], points[1][(j + 1) % m], points[0][i]) >= 0;
        if (flag)
            vertices.emplace_back(points[0][i]);
    }
    for (int i = 0; i < m; ++i)
    {
        bool flag = true;
        for (int j = 0; j < n && flag; ++j)
            flag &= orientation(points[0][j], points[0][(j + 1) % n], points[1][i]) >= 0;
        if (flag)
            vertices.emplace_back(points[1][i]);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vector2di p1 = points[0][i];
            vector2di p2 = points[0][(i + 1) % n];
            vector2di p3 = points[1][j];
            vector2di p4 = points[1][(j + 1) % m];
            if (line_intersection(p1, p2, p3, p4))
            {
                auto ip = intersection_point<double>(p1, p2, p3, p4);
                if (!isnan(ip.x) && !isnan(ip.y))
                    vertices.emplace_back(ip);
            }
        }
    }
    if (vertices.empty())
    {
        cout << 0;
        return 0;
    }
    vertices = monotone_chain(vertices);
    double s = 0;
    for (size_t i = 0; i < vertices.size(); ++i)
        s += vector2df::cross(vertices[i], vertices[(i + 1) % vertices.size()]);
    cout << abs(s) * 0.5;
}