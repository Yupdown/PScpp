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

int intersect(vector2d p1, vector2d p2, vector2d p3, vector2d p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    int result;
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
                result = 2;
            else if (max(x3, x4) == min(x1, x2))
                result = 2;
            else
                result = -1;
        }
    }
    else
        result = (o1 * o2 <= 0) && (o3 * o4 <= 0) ? (o3 == 0 || o4 == 0 ? 2 : 1) : 0;

    return result;
}

int main()
{

    int t;
    cin >> t;

    while (t-- > 0)
    {
        int64 xmin, ymin, xmax, ymax;
        cin >> xmin >> ymin >> xmax >> ymax;

        vector2d p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;

        vector2d edge[][2]
        {
            {{xmin, ymin}, {xmin, ymax}},
            {{xmin, ymin}, {xmax, ymin}},
            {{xmax, ymax}, {xmin, ymax}},
            {{xmax, ymax}, {xmax, ymin}}
        };

        int count1 = 0, count2 = 0;
        bool flag = false;

        for (int i = 0; i < 4; i++)
        {
            switch (intersect(edge[i][0], edge[i][1], p1, p2))
            {
            case -1:
                flag = true;
                break;
            case 1:
                count1++;
                break;
            case 2:
                count2++;
                break;
            }
        }

        cout << (flag ? 4 : count1 + count2 / 2) << endl;
    }

    return 0;
}