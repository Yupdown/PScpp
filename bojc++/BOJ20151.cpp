#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int128 = __int128;

struct vector2d
{
    int128 x;
    int128 y;
};

int128 sign(int128 v)
{
    if (v > 0)
        return 1;
    else if (v < 0)
        return -1;
    return 0;
}

struct line2d
{
    static int128 px;
    static bool flag;

    vector2d p1;
    vector2d p2;

    bool operator<(const line2d& rhs) const
    {
        int128 y1 = p1.y * (p2.x - p1.x) + (px - p1.x) * (p2.y - p1.y);
        int128 y2 = rhs.p1.y * (rhs.p2.x - rhs.p1.x) + (px - rhs.p1.x) * (rhs.p2.y - rhs.p1.y);
        int128 y1den = p2.x - p1.x;
        int128 y2den = rhs.p2.x - rhs.p1.x;
        int128 r1[4];
        int128 r2[4];
        int128 mod = 1;
        mod <<= 64;
        r1[0] = (y1 % mod) * (y2den % mod);
        r1[1] = (y1 % mod) * (y2den / mod);
        r1[2] = (y1 / mod) * (y2den % mod);
        r1[3] = (y1 / mod) * (y2den / mod);
        r2[0] = (y2 % mod) * (y1den % mod);
        r2[1] = (y2 % mod) * (y1den / mod);
        r2[2] = (y2 / mod) * (y1den % mod);
        r2[3] = (y2 / mod) * (y1den / mod);
        for (int i = 0; i < 3; ++i)
        {
            r1[i + 1] += r1[i] / mod;
            r1[i] %= mod;
            r2[i + 1] += r2[i] / mod;
            r2[i] %= mod;
        }
        for (int i = 3; i >= 0; --i)
        {
            if (r1[i] != r2[i])
                return r1[i] < r2[i];
        }
        int128 dx1 = p2.x - p1.x;
        int128 dy1 = p2.y - p1.y;
        int128 dx2 = rhs.p2.x - rhs.p1.x;
        int128 dy2 = rhs.p2.y - rhs.p1.y;
        if (flag)
            return dy1 * dx2 > dy2 * dx1;
        else
            return dy1 * dx2 < dy2 * dx1;
    }
};

inline int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int128 v1 = (b.y - a.y) * (c.x - b.x);
    int128 v2 = (b.x - a.x) * (c.y - b.y);
    return v1 > v2 ? 1 : v1 < v2 ? -1 : 0;
}

bool line_intersection(const vector2d& p1, const vector2d& p2, const vector2d& p3, const vector2d& p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (!(o1 || o2 || o3 || o4))
    {
        int128 x1, x2, x3, x4;
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

    return o1 * o2 + o3 * o4 < 0;
}

bool line_intersection(const line2d& l1, const line2d& l2)
{
    return line_intersection(l1.p1, l1.p2, l2.p1, l2.p2);
}

line2d lines[200000];
array<int128, 4> points[400000];
multiset<line2d> intersects;
int128 line2d::px;
bool line2d::flag;
constexpr long long Offset = 2000000001;

int main()
{
    FASTIO();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        lines[i] = { a + b * Offset, b, c + d * Offset, d };

        if (lines[i].p1.x > lines[i].p2.x)
            swap(lines[i].p1, lines[i].p2);

        points[i * 2] = { lines[i].p1.x, 1, lines[i].p1.y, i };
        points[i * 2 + 1] = { lines[i].p2.x, 0, lines[i].p2.y, i };
    }

    sort(points, points + n * 2);
    bool ret = false;
    for (int i = 0; i < n * 2 && !ret; ++i)
    {
        line2d::px = points[i][0];
        line2d::flag = !points[i][1];
        line2d line = lines[points[i][3]];

        if (!line2d::flag)
        {
            auto iter = intersects.insert(line);
            if (next(iter) != intersects.end() && line_intersection(*next(iter), *iter))
                ret = true;
            if (iter != intersects.begin() && line_intersection(*prev(iter), *iter))
                ret = true;
        }
        else
        {
            auto iter = intersects.lower_bound(line);
            if (next(iter) != intersects.end() && iter != intersects.begin() && line_intersection(*prev(iter), *next(iter)))
                ret = true;
            intersects.erase(iter);
        }
    }

    cout << ret;
}