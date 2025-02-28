#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

typedef long long int64;

struct Vector2D
{
    int64 x;
    int64 y;
    double angle;
};

bool compare(const Vector2D& a, const Vector2D& b)
{
    Vector2D pointA = a;
    Vector2D pointB = b;

    if (pointA.angle != pointB.angle)
        return pointA.angle < pointB.angle;
    else if (pointA.y != pointB.y)
        return pointA.y < pointB.y;
    else
        return pointA.x < pointB.x;
}

bool ccw(const Vector2D& a, const Vector2D& b, const Vector2D& c)
{
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y) < 0;
}

int64 ccw2(const Vector2D& a, const Vector2D& b, const Vector2D& c)
{
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

void normalize(double& vecX, double& vecY)
{
    double length = sqrt(vecX * vecX + vecY * vecY);

    vecX /= length;
    vecY /= length;
}

int64 maxDistance(Vector2D* points, int size)
{
    Vector2D bottomPoint = points[0];

    for (int i = 1; i < size; i++)
        bottomPoint = points[i].y < bottomPoint.y || (points[i].y == bottomPoint.y && points[i].x < bottomPoint.x) ? points[i] : bottomPoint;

    for (int i = 0; i < size; i++)
        points[i].angle = atan2(points[i].y - bottomPoint.y, points[i].x - bottomPoint.x);

    std::sort(points, points + size, compare);

    int first = 0, second = 0, next = 1;
    stack<int> shellPointIndexes;
    shellPointIndexes.push(0);

    while (!ccw(points[0], points[next], points[(next + 1) % size]))
    {
        next++;

        if (!(next < size))
        {
            Vector2D va = points[0];
            Vector2D vb = points[size - 1];
            return (va.x - vb.x) * (va.x - vb.x) + (va.y - vb.y) * (va.y - vb.y);
        }
    }

    while (next < size)
    {
        first = second;
        second = next++;
        while (!ccw(points[first], points[second], points[next % size]))
        {
            second = first;
            shellPointIndexes.pop();
            first = shellPointIndexes.top();
        }
        shellPointIndexes.push(second);
    }

    int length = shellPointIndexes.size();
    Vector2D* shellPoints = new Vector2D[length];

    for (int i = 0; i < length; i++)
    {
        shellPoints[i] = points[shellPointIndexes.top()];
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

            Vector2D iVector;
            Vector2D jVector;

            iVector.x = shellPoints[iNext].x - shellPoints[i].x;
            iVector.y = shellPoints[iNext].y - shellPoints[i].y;

            jVector.x = shellPoints[jNext].x - shellPoints[j].x;
            jVector.y = shellPoints[jNext].y - shellPoints[j].y;

            Vector2D zeroVector;

            zeroVector.x = 0;
            zeroVector.y = 0;

            if (ccw2(zeroVector, iVector, jVector) < 0)
                j = jNext;
            else
                break;
        } while (true);

        Vector2D deltaVector;
        deltaVector.x = shellPoints[j].x - shellPoints[i].x;
        deltaVector.y = shellPoints[j].y - shellPoints[i].y;

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

    Vector2D* points = new Vector2D[n];

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    cout << maxDistance(points, n) << endl;
    delete[] points;

    return 0;
}