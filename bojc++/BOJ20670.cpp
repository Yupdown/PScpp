#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int64;

struct vector2d
{
    int64 x;
    int64 y;

    vector2d() : vector2d(0LL, 0LL) {}
    vector2d(int64 x, int64 y)
    {
        this->x = x;
        this->y = y;
    }

    vector2d operator+(const vector2d& other)
    {
        return vector2d(x + other.x, y + other.y);
    }

    vector2d operator-(const vector2d& other)
    {
        return vector2d(x - other.x, y - other.y);
    }

    vector2d operator+()
    {
        return vector2d(x, y);
    }

    vector2d operator-()
    {
        return vector2d(-x, -y);
    }
};

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : (result < 0 ? -1 : 0);
}

bool get_included_convexhull(vector2d point, vector<vector2d>& convexhull)
{
    int size = convexhull.size();
    if (orientation(convexhull[0], convexhull[1], point) > 0)
        return false;
    if (orientation(convexhull[0], convexhull[size - 1], point) < 0)
        return false;

    int first = 1, last = size - 1, target = 0;
    while (first + 1 < last)
    {
        int mid = (first + last) / 2;
        if (orientation(convexhull[0], convexhull[mid], point) <= 0)
            first = mid;
        else
            last = mid;
    }
    return orientation(convexhull[first], convexhull[(first + 1) % size], point) < 0;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector2d> polygonA;
    vector<vector2d> polygonB;
    polygonA.resize(n);
    polygonB.resize(m);

    for (int i = 0; i < n; i++)
        cin >> polygonA[i].x >> polygonA[i].y;
    for (int i = 0; i < m; i++)
        cin >> polygonB[i].x >> polygonB[i].y;

    int count = 0;
    for (int i = 0; i < k; i++)
    {
        vector2d point;
        cin >> point.x >> point.y;
        if (!get_included_convexhull(point, polygonA) || get_included_convexhull(point, polygonB))
            count++;
    }

    if (count > 0)
        cout << count << endl;
    else
        cout << "YES" << endl;
    return 0;
}