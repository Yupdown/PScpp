#define _USE_MATH_DEFINES
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

using vector2di = vector2d<__int128>;
using vector2df = vector2d<long double>;

vector2di points[100000];
__int128 area_psum[100001];
vector2di cent_psum[100001];

long double get_volume(int n, int lhs, int rhs)
{
    __int128 area;
    vector2df cent;
    if (lhs > rhs)
    {
        area = area_psum[n] - (area_psum[lhs] - area_psum[rhs] - vector2di::cross(points[rhs] - points[0], points[lhs] - points[0]));
        cent = cent_psum[n] - (cent_psum[lhs] - cent_psum[rhs] + (points[lhs] + points[rhs] - points[0] * 2) * vector2di::cross(points[lhs] - points[0], points[rhs] - points[0]));
    }
    else
    {
        area = area_psum[rhs] - area_psum[lhs] - vector2di::cross(points[lhs] - points[0], points[rhs] - points[0]);
        cent = cent_psum[rhs] - cent_psum[lhs] + (points[rhs] + points[lhs] - points[0] * 2) * vector2di::cross(points[rhs] - points[0], points[lhs] - points[0]);
    }
    cent = vector2df(points[0]) + cent / (area * 3);
    vector2df norm = points[rhs] - points[lhs];
    norm /= norm.magnitude();
    norm = vector2df(norm.y, -norm.x);
    long double dist = vector2df::dot(cent - points[lhs], norm);
    return M_PI * dist * area;
}

int main()
{
	FASTIO();
    PRECISION(10);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        long long x, y;
        cin >> x >> y;
        points[i] = vector2di(x, y);
    }
    for (int i = 2; i < n + 1; ++i)
    {
        auto area = vector2di::cross(points[i - 1] - points[0], points[i % n] - points[0]);
        area_psum[i] = area_psum[i - 1] + area;
        cent_psum[i] = cent_psum[i - 1] + (points[i - 1] + points[i % n] - points[0] * 2) * area;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (vector2di::cross(points[(a + 1) % n] - points[a], points[b] - points[a]) == 0 || vector2di::cross(points[(b + 1) % n] - points[b], points[a] - points[b]) == 0)
            cout << "0\n";
        else
            cout << min(get_volume(n, a, b), get_volume(n, b, a)) << "\n";
    }
}