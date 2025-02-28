#include <bits/stdc++.h>

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

    bool condition1 = orientation(p1, p2, p3) * orientation(p1, p2, p4) < 0;
    bool condition2 = orientation(p3, p4, p1) * orientation(p3, p4, p2) < 0;

    cout << (condition1 && condition2) << endl;
    return 0;
}