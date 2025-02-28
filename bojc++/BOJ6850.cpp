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
    vector2d bottomPoint = points[0];

    for (int i = 1; i < size; i++)
        bottomPoint = points[i].y < bottomPoint.y ? points[i] : bottomPoint;

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
    size = sortedPoints.size();

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

int main()
{
    int n;
    cin >> n;

    vector2d* points = new vector2d[n];

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<vector2d> convexhullPoints = get_convexhull(points, n);
    int size = convexhullPoints.size();

    double result = 0.0;
    for (int i = 0; i < size; i++)
    {
        result += (double)convexhullPoints[i].x * convexhullPoints[(i + 1) % size].y;
        result -= (double)convexhullPoints[(i + 1) % size].x * convexhullPoints[i].y;
    }

    cout << floor(abs(result) * 0.01) << endl;

    delete[] points;
    return 0;
}