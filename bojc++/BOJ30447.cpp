#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr double EPS = 1e-9;

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
inline T dot_product(const vector2d<T>& lhs, const vector2d<T>& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

template <typename T>
inline T cross_product(const vector2d<T>& lhs, const vector2d<T>& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

using int64 = long long;
using t_line = pair<vector2d<double>, vector2d<double>>;

bool parallel(int lhs, int rhs, t_line* p)
{
    return fabs(cross_product(p[lhs].second, p[rhs].second)) < EPS;
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

double solution(int n, t_line* p)
{
    sort(p, p + n, [](const t_line& lhs, const t_line& rhs) { return atan2(lhs.second.y, lhs.second.x) < atan2(rhs.second.y, rhs.second.x); });

    deque<int> dq;
    for (int i = 0; i < n; ++i)
    {
        while (dq.size() > 1)
        {
            int p1 = *(dq.end() - 2);
            int p2 = *(dq.end() - 1);
            auto v = intersection_point(p1, p2, p);
            if (cross_product(p[i].second, v - p[i].first) > -EPS)
                break;
            dq.pop_back();
        }

        while (dq.size() > 1)
        {
            int p1 = *(dq.begin());
            int p2 = *(dq.begin() + 1);
            auto v = intersection_point(p1, p2, p);
            if (cross_product(p[i].second, v - p[i].first) > -EPS)
                break;
            dq.pop_front();
        }

        if (dq.size() > 0 && parallel(dq.back(), i, p))
        {
            if (dot_product(p[dq.back()].second, p[i].second) < 0)
                return 0;
            if (cross_product(p[dq.back()].second, p[i].first - p[dq.back()].first) > -EPS)
                dq.pop_back();
            else
                continue;
        }

        dq.push_back(i);
    }

    while (dq.size() > 2)
    {
        int p1 = *(dq.end() - 2);
        int p2 = *(dq.end() - 1);
        auto v = intersection_point(p1, p2, p);
        if (cross_product(p[dq.front()].second, v - p[dq.front()].first) > -EPS)
            break;
        dq.pop_back();
    }

    while (dq.size() > 2)
    {
        int p1 = *(dq.begin());
        int p2 = *(dq.begin() + 1);
        auto v = intersection_point(p1, p2, p);
        if (cross_product(p[dq.back()].second, v - p[dq.back()].first) > -EPS)
            break;
        dq.pop_front();
    }

    if (dq.size() < 3)
        return 0;

    vector<vector2d<double>> points;
    points.push_back(intersection_point(dq.back(), dq.front(), p));
    for (auto iter = dq.begin(); iter != dq.end() - 1; ++iter)
        points.push_back(intersection_point(*iter, *(iter + 1), p));
    double ret = cross_product(points.back(), points.front());
    for (auto iter = points.begin() + 1; iter != points.end(); ++iter)
        ret += cross_product(*prev(iter), *iter);
    return abs(ret) * 0.5;
}

int main()
{
    FASTIO();

    int w, h;
    vector2d<double> va, vb;
    cin >> w >> h >> va.x >> va.y >> vb.x >> vb.y;
    if (cross_product(va, vb) < 0)
        swap(va, vb);

    vector<t_line> lines;
    lines.emplace_back(vector2d<double>(0, 0), vector2d<double>(1, 0));
    lines.emplace_back(vector2d<double>(w, 0), vector2d<double>(0, 1));
    lines.emplace_back(vector2d<double>(w, h), vector2d<double>(-1, 0));
    lines.emplace_back(vector2d<double>(0, h), vector2d<double>(0, -1));
    lines.emplace_back(va, vb - va);

    vector2d<double> norm = (vb - va).normalized();
    vector2d<double> diag = vector2d<double>(-norm.y, norm.x);
    lines.emplace_back(lines[3].first + diag * cross_product(lines[3].first - va, norm) * 2, lines[0].second + diag * cross_product(lines[0].second, norm) * 2);
    lines.emplace_back(lines[2].first + diag * cross_product(lines[2].first - va, norm) * 2, lines[3].second + diag * cross_product(lines[3].second, norm) * 2);
    lines.emplace_back(lines[1].first + diag * cross_product(lines[1].first - va, norm) * 2, lines[2].second + diag * cross_product(lines[2].second, norm) * 2);
    lines.emplace_back(lines[0].first + diag * cross_product(lines[0].first - va, norm) * 2, lines[1].second + diag * cross_product(lines[1].second, norm) * 2);

    cout << static_cast<int>(w * h - solution(lines.size(), lines.data()) + 1e-6);
}