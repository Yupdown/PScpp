#include <iostream>
#include <algorithm>
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

bool compare(const pair<vector2d, double>& a, const pair<vector2d, double>& b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else if (a.first.x != b.first.y)
        return a.first.y < b.first.y;
    else
        return a.first.x < b.first.x;
}

int64 orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    return (int64)(b.y - a.y) * (c.x - b.x) - (int64)(b.x - a.x) * (c.y - b.y);
}

int64 get_result(vector2d* points, int size)
{
    vector2d bottomPoint = points[0];

    for (int i = 1; i < size; i++)
        bottomPoint = points[i].y < bottomPoint.y || (points[i].y == bottomPoint.y && points[i].x < bottomPoint.x) ? points[i] : bottomPoint;

    pair<vector2d, double>* pointAnglePairs = new pair<vector2d, double>[size];
    for (int i = 0; i < size; i++)
    {
        pointAnglePairs[i].first = points[i];
        pointAnglePairs[i].second = atan2(points[i].y - bottomPoint.y, points[i].x - bottomPoint.x);
    }

    std::sort(pointAnglePairs, pointAnglePairs + size, compare);

    vector2d* sortedPoints = new vector2d[size];
    for (int i = 0; i < size; i++)
        sortedPoints[i] = pointAnglePairs[i].first;

    int first = 0, second = 0, next = 1;
    stack<int> shellPointIndexes;
    shellPointIndexes.push(0);

    while (orientation(sortedPoints[0], sortedPoints[next], sortedPoints[(next + 1) % size]) >= 0)
    {
        next++;

        if (!(next < size))
        {
            vector2d va = sortedPoints[0];
            vector2d vb = sortedPoints[size - 1];
            return (va.x - vb.x) * (va.x - vb.x) + (va.y - vb.y) * (va.y - vb.y);
        }
    }

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
    vector2d* shellPoints = new vector2d[length];

    for (int i = 0; i < length; i++)
    {
        shellPoints[i] = sortedPoints[shellPointIndexes.top()];
        shellPointIndexes.pop();
    }

    int64 distanceSqrMax = 0;
    int j = 1;

    for (int i = 0; i < length; i++)
    {
        int iNext = (i + 1) % length;

        do
        {
            int jNext = (j + 1) % length;

            vector2d iVector = shellPoints[iNext] - shellPoints[i];
            vector2d jVector = shellPoints[jNext] - shellPoints[j];
            vector2d zeroVector = vector2d();

            if (orientation(zeroVector, iVector, jVector) > 0)
                j = jNext;
            else
                break;
        } while (true);

        vector2d deltaVector = shellPoints[j] - shellPoints[i];
        int64 distanceSqr = deltaVector.x * deltaVector.x + deltaVector.y * deltaVector.y;

        if (distanceSqr > distanceSqrMax)
            distanceSqrMax = distanceSqr;
    }

    delete[] shellPoints;
    return distanceSqrMax;
}

int main()
{
    int n;
    cin >> n;

    vector2d* points = new vector2d[n];

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    cout << get_result(points, n) << endl;
    delete[] points;

    return 0;
}