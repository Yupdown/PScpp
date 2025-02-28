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
    if ((!o1 && !o2) || (!o3 && !o4))
    {
        if (p1.x == p2.x && p3.x == p4.x && p1.x == p3.x)
            result = max(p1.y, p2.y) >= min(p3.y, p4.y) && max(p3.y, p4.y) >= min(p1.y, p2.y);
        else
            result = max(p1.x, p2.x) >= min(p3.x, p4.x) && max(p3.x, p4.x) >= min(p1.x, p2.x);
    }
    else
        result = (o1 * o2 <= 0) && (o3 * o4 <= 0);

    cout << result << endl;
    return 0;
}