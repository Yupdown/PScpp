#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>

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

bool intersect(vector2d p1, vector2d p2, vector2d p3, vector2d p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

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

        return max(abs(min(x1, x2) - max(x3, x4)), abs(min(x3, x4) - max(x1, x2))) <= abs(x1 - x2) + abs(x3 - x4);
    }
    else
        return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

vector<vector2d> get_convexhull(vector2d* points, int size)
{
    vector2d bottomPoint = points[0];

    for (int i = 1; i < size; i++)
        bottomPoint = (points[i].y == bottomPoint.y ? points[i].x < bottomPoint.x : points[i].y < bottomPoint.y) ? points[i] : bottomPoint;

    pair<vector2d, double>* pointAnglePairs = new pair<vector2d, double>[size];
    for (int i = 0; i < size; i++)
    {
        pointAnglePairs[i].first = points[i];
        pointAnglePairs[i].second = atan2(points[i].y - bottomPoint.y, points[i].x - bottomPoint.x);
    }

    std::sort(pointAnglePairs, pointAnglePairs + size, [=](const pair<vector2d, double>& a, const pair<vector2d, double>& b) -> bool
        {
            if (a.second == b.second)
            {
                vector2d aDelta = (vector2d)a.first - bottomPoint;
                vector2d bDelta = (vector2d)b.first - bottomPoint;

                return aDelta.x * aDelta.x + aDelta.y * aDelta.y < bDelta.x * bDelta.x + bDelta.y * bDelta.y;
            }
            return a.second < b.second;
        });

    vector<vector2d> sortedPoints;
    sortedPoints.push_back(pointAnglePairs[0].first);

    for (int i = 1; i < size; i++)
    {
        if (i < size - 1)
        {
            if (pointAnglePairs[i].second == pointAnglePairs[i + 1].second)
                continue;
        }
        sortedPoints.push_back(pointAnglePairs[i].first);
    }

    delete[] pointAnglePairs;
    size = sortedPoints.size();

    if (size > 2)
    {
        int first = 0, second = 0, next = 1;
        stack<int> shellPointIndexes;
        shellPointIndexes.push(0);

        while (next < size)
        {
            first = second;
            second = next++;
            while (orientation(sortedPoints[first], sortedPoints[second], sortedPoints[next % size]) >= 0)
            {
                second = first;
                shellPointIndexes.pop();
                first = shellPointIndexes.top();
            }
            shellPointIndexes.push(second);
        }

        int length = shellPointIndexes.size();
        vector<vector2d> shellPoints = vector<vector2d>(length);

        for (int i = 0; i < length; i++)
        {
            shellPoints[length - i - 1] = sortedPoints[shellPointIndexes.top()];
            shellPointIndexes.pop();
        }

        return shellPoints;
    }
    else
        return sortedPoints;
}

bool check_in(vector2d point, vector<vector2d> polygon)
{
    int count = 0;

    for (int i = 0; i < polygon.size(); i++)
    {
        vector2d lineA = polygon[i];
        vector2d lineB = polygon[(i + 1) % polygon.size()];

        if (point.y < lineA.y != point.y < lineB.y)
        {
            double cross = (double)(lineB.x - lineA.x) * (point.y - lineA.y) / (lineB.y - lineA.y) + lineA.x;

            if (cross == point.x)
                return true;
            else if (cross > point.x)
                count++;
        }
    }

    return (count % 2) > 0;
}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        vector2d points[100];

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        vector<vector2d> hullPointsA = get_convexhull(points, n);
        n = hullPointsA.size();

        for (int i = 0; i < m; i++)
            cin >> points[i].x >> points[i].y;

        vector<vector2d> hullPointsB = get_convexhull(points, m);
        m = hullPointsB.size();

        bool result = true;
        for (int i = 0; i < n; i++)
            result &= !check_in(hullPointsA[i], hullPointsB);

        for (int i = 0; i < m; i++)
            result &= !check_in(hullPointsB[i], hullPointsA);

        if (n > 1 && m > 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int iNext = (i + 1) % n;
                    int jNext = (j + 1) % m;

                    result &= !intersect(hullPointsA[i], hullPointsA[iNext], hullPointsB[j], hullPointsB[jNext]);
                }
            }
        }

        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}