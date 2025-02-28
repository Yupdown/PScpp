#include <iostream>
#include <cmath>

using namespace std;
typedef long long int64;

struct vector2d
{
    int64 x;
    int64 y;
};

struct intersect_result
{
    int r;
    double rx;
    double ry;
};

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

intersect_result intersect(const vector2d& p1, const vector2d& p2, const vector2d& p3, const vector2d& p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    intersect_result result;
    if ((!o1 && !o2) || (!o3 && !o4))
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

        result.r = max(abs(min(x1, x2) - max(x3, x4)), abs(min(x3, x4) - max(x1, x2))) <= abs(x1 - x2) + abs(x3 - x4);

        if (result.r)
        {
            vector2d v = p1;
            if (max(x1, x2) == min(x3, x4))
                v = x1 > x2 ? p1 : p2;
            else if (max(x3, x4) == min(x1, x2))
                v = x3 > x4 ? p3 : p4;
            else
                result.r = -1;

            result.rx = v.x;
            result.ry = v.y;
        }
    }
    else
    {
        result.r = (o1 * o2 <= 0) && (o3 * o4 <= 0);
        double p = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
        result.rx = (double)((p1.x * p2.y - p2.x * p1.y) * (p3.x - p4.x) - (p3.x * p4.y - p4.x * p3.y) * (p1.x - p2.x)) / p;
        result.ry = (double)((p1.x * p2.y - p2.x * p1.y) * (p3.y - p4.y) - (p3.x * p4.y - p4.x * p3.y) * (p1.y - p2.y)) / p;
    }

    return result;
}

bool overlap_line(const vector2d& p1, const vector2d& p2)
{
    if (p1.x == p2.x)
        return p1.y * p2.y < 0 && p1.x > -10 && p1.x < 10;

    if (p1.x >= 10 && p2.x >= 10 || p1.x <= -10 && p2.x <= -10 || p1.y >= 10 && p2.y >= 10 || p1.y <= -10 && p2.y <= -10)
        return false;

    int o1 = orientation(p1, p2, { -10, -10 });
    int o2 = orientation(p1, p2, { -10, 10 });
    int o3 = orientation(p1, p2, { 10, -10 });
    int o4 = orientation(p1, p2, { 10, 10 });

    return !(o1 == o2 && o2 == o3 && o3 == o4);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    vector2d p[100][2];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i][0].x >> p[i][0].y >> p[i][1].x >> p[i][1].y;

    int c = 1;
    for (int i = 0; i < n; ++i)
    {
        int cd = 1;

        if (!overlap_line(p[i][0], p[i][1]))
            continue;

        for (int j = 0; j < i; ++j)
        {
            intersect_result result = intersect(p[i][0], p[i][1], p[j][0], p[j][1]);

            if (result.r != 1)
                continue;

            cd += result.rx > -10 && result.rx < 10 && result.ry > -10 && result.ry < 10;
        }

        c += cd;
    }

    cout << c << endl;
    return 0;
}