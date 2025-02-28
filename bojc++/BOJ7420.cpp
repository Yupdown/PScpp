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

int main()
{
    int n, l;
    cin >> n >> l;

    vector2d points[1000];
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    double result = (double)l * 2.0 * 3.1415926535;
    vector<vector2d> hullPoints = get_convexhull(points, n);
    for (int i = 0; i < hullPoints.size(); i++)
    {
        vector2d delta = hullPoints[(i + 1) % hullPoints.size()] - hullPoints[i];
        result += sqrt(delta.x * delta.x + delta.y * delta.y);
    }

    cout << round(result) << endl;
    return 0;
}