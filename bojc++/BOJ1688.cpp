#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

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

inline int64 distance_sqr(const vector2d& lhs, const vector2d& rhs)
{
    int64 dx = lhs.x - rhs.x;
    int64 dy = lhs.y - rhs.y;
    return dx * dx + dy * dy;
}

inline bool line_contains_point(const vector2d& ll, const vector2d& lr , const vector2d& p)
{
    if (orientation(ll, lr, p) != 0)
        return false;
    int64 d1 = distance_sqr(ll, lr);
    int64 d2 = distance_sqr(ll, p);
    int64 d3 = distance_sqr(lr, p);
    return d2 <= d1 && d3 <= d1;
}

bool line_intersection(const vector2d& p1, const vector2d& p2, const vector2d& p3, const vector2d& p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (!(o1 || o2 || o3 || o4))
        return false;
    return (o1 * o2 <= 0) && ((o3 >= 0 && o4 < 0) || (o3 < 0 && o4 >= 0));
}

vector2d table[10000];

int main()
{
    FASTIO();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> table[i].x >> table[i].y;

    for (int i = 0; i < 3; ++i)
    {
        vector2d v;
        cin >> v.x >> v.y;

        bool flag = true;
        int cnt = 0;
        for (int j = 0; j < n && flag; ++j)
        {
            if (line_contains_point(table[j], table[(j + 1) % n], v))
                flag = false;
            if (line_intersection(table[j], table[(j + 1) % n], v, vector2d{ 1 << 30, v.y }))
                cnt += 1;
        }

        cout << (!flag || (cnt & 1)) << '\n';
    }
}