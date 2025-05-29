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

    static T dot(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
    static T cross(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }
};

template <typename T>
struct vector3d
{
    T x, y, z;
    vector3d() : vector3d(0, 0, 0) {}
    vector3d(T x, T y, T z) : x(x), y(y), z(z) {}

    T sqr_magnitude() const { return dot(*this, *this); }
    double magnitude() const { return sqrt(sqr_magnitude()); }
    vector3d normalized() const { return *this / magnitude(); }
    vector3d operator-() const { return { -x, -y, -z }; };
    vector3d operator+(const vector3d& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z }; };
    vector3d operator-(const vector3d& rhs) const { return *this + (-rhs); };
    vector3d operator*(const T& rhs) const { return { x * rhs, y * rhs, z * rhs }; };
    vector3d operator/(const T& rhs) const { return { x / rhs, y / rhs, z / rhs }; };
    bool operator==(const vector3d& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; };
    bool operator!=(const vector3d& rhs) const { return !(*this == rhs); };

    static T dot(const vector3d& lhs, const vector3d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }
    static vector3d cross(const vector3d& lhs, const vector3d& rhs) { return { lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x }; }
};

using vector2df = vector2d<double>;
using vector3df = vector3d<double>;

struct segment
{
    segment* prev = nullptr;
    segment* next = nullptr;
    vector2df p0, p1;
    double h = 0;
    vector3df bx;
    vector3df by;
    vector3df bz;
    int flag = 0;
};

vector2df xyi[100000];
double ai[100000];
segment table[100000];

double calc_height(const segment& s)
{
    double da = (s.p1 - s.p0).magnitude();
    vector3df cv0 = vector3df::cross(s.prev->bz, s.bz);
    vector3df cv1 = vector3df::cross(s.bz, s.next->bz);
    double dx0 = vector3df::dot(s.bx, cv0);
    double dy0 = vector3df::dot(s.by, cv0);
    double dx1 = vector3df::dot(s.bx, cv1);
    double dy1 = vector3df::dot(s.by, cv1);
    double y = dy0 * dy1 * da / (dx0 * dy1 - dx1 * dy0);
    return s.h + y * s.by.z;
}

double update_segment(segment& s, double h1, double h2, double h)
{
    h1 = (max(h1, s.h) - s.h) / s.by.z;
    h2 = (min(h2, h) - s.h) / s.by.z;

    vector3df cv0 = vector3df::cross(s.prev->bz, s.bz);
    vector3df cv1 = vector3df::cross(s.bz, s.next->bz);
    double dx0 = vector3df::dot(s.bx, cv0) / vector3df::dot(s.by, cv0);
    double dx1 = vector3df::dot(s.bx, cv1) / vector3df::dot(s.by, cv1);
    double y = (h - s.h) / s.by.z;

    vector2df p2 = vector2df(dx0, 1) * y;
    vector2df p3 = vector2df(dx1, 1) * y;

    double d = (s.p0 - s.p1).magnitude();
    double da = d - dx0 * h1 + dx1 * h1;
    double db = d - dx0 * h2 + dx1 * h2;

    vector2df bx = vector2df(s.bx.x, s.bx.y);
    vector2df by = vector2df(s.by.x, s.by.y);
    s.p0 += bx * p2.x + by * p2.y;
    s.p1 += bx * p3.x + by * p3.y;

    s.h = h;
    double ret = h1 < h2 ? (da + db) * (h2 - h1) * 0.5 : 0;
    return ret;
}

int main()
{
	FASTIO();
    PRECISION(6);

    int n, h1, h2;
    cin >> n >> h1 >> h2;

    for (int i = 0; i < n; ++i)
        cin >> xyi[i].x >> xyi[i].y;
    for (int i = 0; i < n; ++i)
        cin >> ai[i];
    for (int i = 0; i < n; ++i)
    {
        table[i].next = &table[(i + 1) % n];
        table[i].prev = &table[(i + n - 1) % n];
        table[i].p0 = xyi[i];
        table[i].p1 = xyi[(i + 1) % n];
        vector2df bx2 = (table[i].p1 - table[i].p0).normalized();
        table[i].bx = vector3df(bx2.x, bx2.y, 0);
        table[i].by = vector3df(-bx2.y, bx2.x, tan(ai[i] * M_PI / 180)).normalized();
        table[i].bz = vector3df::cross(table[i].bx, table[i].by);
    }

    // no more colinear
    for (int i = 0; i < n; ++i)
    {
        segment* curr = &table[i];
        if (vector2df::cross(curr->p1 - curr->p0, curr->next->p1 - curr->next->p0) == 0)
        {
            // eliminate current
            curr->flag = -1;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            --n;
        }
    }

    // if the polygon is degenerate
    if (n <= 2)
    {
        cout << 0;
        return 0;
    }

    priority_queue<tuple<double, segment*>> pq;

    segment* curr = find_if_not(begin(table), end(table), [](const auto& s) { return s.flag < 0; });
    for (int i = 0; i < n; ++i, curr = curr->next)
    {
        double h = calc_height(*curr);
        if (h >= 0)
            pq.emplace(-h, curr);
    }

    double ret = 0;
    while (!pq.empty() && n > 2)
    {
        auto [h, curr] = pq.top();
        h = -h;
        pq.pop();

        if (curr->flag < 0)
            continue;

        ret += update_segment(*curr, h1, h2, h);
        ret += update_segment(*curr->prev, h1, h2, h);
        ret += update_segment(*curr->next, h1, h2, h);

        curr->flag = -1;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        double hp = calc_height(*curr->prev);
        if (hp >= h)
            pq.emplace(-hp, curr->prev);
        double hn = calc_height(*curr->next);
        if (hn >= h)
            pq.emplace(-hn, curr->next);

        --n;
    }

    cout << ret;
}