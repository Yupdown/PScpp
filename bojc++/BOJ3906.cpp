#include <bits/stdc++.h>
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
};

template <typename T>
inline T cross_product(const vector2d<T>& lhs, const vector2d<T>& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

using int64 = long long;
using t_line = pair<vector2d<double>, vector2d<double>>;

bool parallel(int lhs, int rhs, t_line* p)
{
    return cross_product(p[lhs].second, p[rhs].second) == 0;
}


vector2d<double> intersection_point(int lhs, int rhs, t_line* p)
{
    double a11 = p[lhs].second.x;
    double a12 = -p[rhs].second.x;
    double a21 = p[lhs].second.y;
    double a22 = -p[rhs].second.y;
    double det = a11 * a22 - a12 * a21;
    double t = (a22 / det) * (p[rhs].first.x - p[lhs].first.x) - (a12 / det) * (p[rhs].first.y - p[lhs].first.y);
    return p[lhs].first + p[lhs].second * t;
}

int solution(int n, t_line* p)
{
    sort(p, p + n, [](const t_line& lhs, const t_line& rhs) { return atan2(lhs.second.y, lhs.second.x) < atan2(rhs.second.y, rhs.second.x); });

    deque<int> dq;
    dq.push_back(0);
    dq.push_back(1);
    for (int i = 2; i < n; ++i)
    {
        while (dq.size() >= 2)
        {
            int p1 = *(dq.end() - 2);
            int p2 = *(dq.end() - 1);

            if (!parallel(p1, p2, p))
            {
                auto v = intersection_point(p1, p2, p);
                if (cross_product(p[i].second, v - p[i].first) >= 0)
                    break;
            }
            dq.pop_back();
        }
        while (dq.size() >= 2)
        {
            int p1 = *(dq.begin());
            int p2 = *(dq.begin() + 1);

            if (!parallel(p1, p2, p))
            {
                auto v = intersection_point(p1, p2, p);
                if (cross_product(p[i].second, v - p[i].first) >= 0)
                    break;
            }
            dq.pop_front();
        }
        dq.push_back(i);
    }

    while (dq.size() >= 2)
    {
        int p1 = *(dq.end() - 2);
        int p2 = *(dq.end() - 1);

        if (!parallel(p1, p2, p))
        {
            auto v = intersection_point(p1, p2, p);
            if (cross_product(p[dq.front()].second, v - p[dq.front()].first) >= 0)
                break;
        }
        dq.pop_back();
    }

    while (dq.size() >= 2)
    {
        int p1 = *(dq.begin());
        int p2 = *(dq.begin() + 1);

        if (!parallel(p1, p2, p))
        {
            auto v = intersection_point(p1, p2, p);
            if (cross_product(p[dq.back()].second, v - p[dq.back()].first) >= 0)
                break;
        }
        dq.pop_front();
    }

    return dq.size() >= 3;
}

t_line lines[50];

int main()
{
    FASTIO();
    PRECISION(8);

    int n;
    while (cin >> n && n > 0)
    {
        for (int i = 0; i < n; ++i)
            cin >> lines[i].first.x >> lines[i].first.y;
        for (int i = 0; i < n; ++i)
        {
            lines[i].second.x = lines[(i + 1) % n].first.x - lines[i].first.x;
            lines[i].second.y = lines[(i + 1) % n].first.y - lines[i].first.y;
        }

        cout << solution(n, lines) << "\n";
    }
}