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

int64 orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    return (int64)(b.y - a.y) * (c.x - b.x) - (int64)(b.x - a.x) * (c.y - b.y);
}

vector<vector2d> get_convexhull(vector2d* points, int size)
{
    vector2d topPoints = points[0];

    for (int i = 1; i < size; i++)
        topPoints = (points[i].y == topPoints.y ? points[i].x < topPoints.x : points[i].y > topPoints.y) ? points[i] : topPoints;

    pair<vector2d, double>* pointAnglePairs = new pair<vector2d, double>[size];
    for (int i = 0; i < size; i++)
    {
        pointAnglePairs[i].first = points[i];
        pointAnglePairs[i].second = atan2(topPoints.y - points[i].y, topPoints.x - points[i].x);
    }

    std::sort(pointAnglePairs, pointAnglePairs + size, [=](const pair<vector2d, double>& a, const pair<vector2d, double>& b) -> bool
        {
            if (a.second == b.second)
            {
                vector2d aDelta = (vector2d)a.first - topPoints;
                vector2d bDelta = (vector2d)b.first - topPoints;

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
    size = sortedPoints.size();

    int first = 0, second = 0, next = 1;
    stack<int> shellPointIndexes;
    shellPointIndexes.push(0);

    if (size > 2)
    {
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
    }
    else
        shellPointIndexes.push(1);

    int length = shellPointIndexes.size();
    vector<vector2d> shellPoints = vector<vector2d>(length);

    shellPoints[0] = topPoints;
    for (int i = 1; i < length; i++)
    {
        shellPoints[i] = sortedPoints[shellPointIndexes.top()];
        shellPointIndexes.pop();
    }

    return shellPoints;
}

int main()
{
    int p;
    cin >> p;

    while (p-- > 0)
    {
        int n;
        cin >> n;

        vector2d* points = new vector2d[n];

        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        vector<vector2d> convexhullPoints = get_convexhull(points, n);
        int size = convexhullPoints.size();

        cout << size << endl;
        for (int i = 0; i < size; i++)
            cout << convexhullPoints[i].x << ' ' << convexhullPoints[i].y << endl;

        delete[] points;
    }

    return 0;
}