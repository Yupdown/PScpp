#include <iostream>
#include <math.h>

using namespace std;
typedef long long int64;

struct vector2d
{
    int64 x;
    int64 y;
};

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

int main()
{
    vector2d p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    int result;
    double rx, ry;
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

        result = max(abs(min(x1, x2) - max(x3, x4)), abs(min(x3, x4) - max(x1, x2))) <= abs(x1 - x2) + abs(x3 - x4);

        if (result)
        {
            vector2d v = p1;
            if (max(x1, x2) == min(x3, x4))
                v = x1 > x2 ? p1 : p2;
            else if (max(x3, x4) == min(x1, x2))
                v = x3 > x4 ? p3 : p4;
            else
                result = -1;

            rx = v.x;
            ry = v.y;
        }
    }
    else
    {
        result = (o1 * o2 <= 0) && (o3 * o4 <= 0);
        double p = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
        rx = (double)((p1.x * p2.y - p2.x * p1.y) * (p3.x - p4.x) - (p3.x * p4.y - p4.x * p3.y) * (p1.x - p2.x)) / p;
        ry = (double)((p1.x * p2.y - p2.x * p1.y) * (p3.y - p4.y) - (p3.x * p4.y - p4.x * p3.y) * (p1.y - p2.y)) / p;
    }

    cout.precision(10);
    cout << (result != 0) << endl;
    if (result > 0)
        cout << rx << ' ' << ry << endl;
    return 0;
}