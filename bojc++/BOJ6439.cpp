#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

struct vector2d
{
    int64 x;
    int64 y;
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

bool get_result(const vector2d& p1, const vector2d& p2, const vector2d& r1, const vector2d& r2)
{
    if (p1.x >= r1.x && p1.x <= r2.x && p1.y >= r1.y && p1.y <= r2.y)
        return true;
    if (p2.x >= r1.x && p2.x <= r2.x && p2.y >= r1.y && p2.y <= r2.y)
        return true;

    bool c1 = line_intersection(p1, p2, { r1.x, r1.y }, { r1.x, r2.y });
    bool c2 = line_intersection(p1, p2, { r1.x, r1.y }, { r2.x, r1.y });
    bool c3 = line_intersection(p1, p2, { r2.x, r2.y }, { r1.x, r2.y });
    bool c4 = line_intersection(p1, p2, { r2.x, r2.y }, { r2.x, r1.y });

    return c1 || c2 || c3 || c4;
}

int main()
{
    FASTIO();

    int t;
    cin >> t;

    while (t-- > 0)
    {
        vector2d p1, p2, r1, r2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> r1.x >> r1.y >> r2.x >> r2.y;

        if (r1.x > r2.x)
            swap<int64>(r1.x, r2.x);
        if (r1.y > r2.y)
            swap<int64>(r1.y, r2.y);

        cout << (get_result(p1, p2, r1, r2) ? 'T' : 'F') << '\n';
    }

    return 0;
}