#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

struct vector2d
{
    int64 x;
    int64 y;
};

struct line2d
{
    static pair<int64, int64> px;

    vector2d p1;
    vector2d p2;

    bool operator<(const line2d& rhs) const
    {
        double y1 = px.second ? p2.y : p1.y;
        if (p1.x != p2.x)
            y1 = p1.y + static_cast<double>(px.first - p1.x) / (p2.x - p1.x) * (p2.y - p1.y);
        double y2 = px.second ? rhs.p2.y : rhs.p1.y;
        if (rhs.p1.x != rhs.p2.x)
            y2 = rhs.p1.y + static_cast<double>(px.first - rhs.p1.x) / (rhs.p2.x - rhs.p1.x) * (rhs.p2.y - rhs.p1.y);
        return y1 < y2;
    }
};

inline int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

bool line_intersection(const vector2d& p1, const vector2d& p2, const vector2d& p3, const vector2d& p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (!(o1 || o2 || o3 || o4))
    {
        int x1, x2, x3, x4;
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

        return max(abs(min(x1, x2) - max(x3, x4)), abs(min(x3, x4) - max(x1, x2))) <= abs(x1 - x2) + abs(x3 - x4);
    }

    return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

bool line_intersection(const line2d& l1, const line2d& l2)
{
    return line_intersection(l1.p1, l1.p2, l2.p1, l2.p2);
}

line2d lines[200000];
array<int64, 4> points[400000];
multiset<line2d> intersects;
pair<int64, int64> line2d::px;

int main()
{
	FASTIO();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> lines[i].p1.x >> lines[i].p1.y;
        cin >> lines[i].p2.x >> lines[i].p2.y;

        if (lines[i].p1.x > lines[i].p2.x)
            swap(lines[i].p1, lines[i].p2);

        points[i * 2] = { lines[i].p1.x, 0, lines[i].p1.y, i };
        points[i * 2 + 1] = { lines[i].p2.x, 1, lines[i].p2.y, i };
    }

    sort(points, points + n * 2);
    bool ret = false;
    for (int i = 0; i < n * 2 && !ret; ++i)
    {
        line2d::px = make_pair(points[i][0], points[i][1]);

        if (line2d::px.second == 0)
        {
            auto iter = intersects.insert(lines[points[i][3]]);
            if (next(iter) != intersects.end() && line_intersection(*next(iter), *iter))
                ret = true;
            if (iter != intersects.begin() && line_intersection(*prev(iter), *iter))
                ret = true;
        }
        else
        {
            auto iter = intersects.lower_bound(lines[points[i][3]]);
            if (next(iter) != intersects.end() && iter != intersects.begin() && line_intersection(*prev(iter), *next(iter)))
                ret = true;
            intersects.erase(iter);
        }
    }

    cout << ret;
}