#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

typedef struct
{
    int x;
    int y;
    double angle;
}Vec2D;

int compare(const void* a, const void* b)
{
    Vec2D pointA = (*(Vec2D*)a);
    Vec2D pointB = (*(Vec2D*)b);

    if (pointA.angle != pointB.angle)
        return pointA.angle > pointB.angle ? 1 : -1;
    else if (pointA.y != pointB.y)
        return pointA.y > pointB.y ? 1 : -1;
    else
        return pointA.x > pointB.x ? 1 : -1;
}

bool ccw(const Vec2D& a, const Vec2D& b, const Vec2D& c)
{
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y) < 0;
}

void normalize(double& vecX, double& vecY)
{
    double length = sqrt(vecX * vecX + vecY * vecY);

    vecX /= length;
    vecY /= length;
}

double maxDistance(Vec2D* points, int size)
{
    Vec2D bottomPoint = points[0];

    for (int i = 1; i < size; i++)
        bottomPoint = points[i].y < bottomPoint.y || (points[i].y == bottomPoint.y && points[i].x < bottomPoint.x) ? points[i] : bottomPoint;

    for (int i = 0; i < size; i++)
        points[i].angle = atan2((double)points[i].y - bottomPoint.y, (double)points[i].x - bottomPoint.x);

    qsort(points, size, sizeof(Vec2D), compare);

    int first = 0, second = 0, next = 1;
    stack<int> shellPointIndexes;
    shellPointIndexes.push(0);

    while (!ccw(points[0], points[next], points[(next + 1) % size]))
    {
        next++;

        if (!(next < size))
        {
            Vec2D deltaVector;
            deltaVector.x = points[size - 1].x - points[0].x;
            deltaVector.y = points[size - 1].y - points[0].y;

            return sqrt(deltaVector.x * deltaVector.x + deltaVector.y * deltaVector.y);
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
    Vec2D* shellPoints = new Vec2D[length];

    for (int i = 0; i < length; i++)
    {
        shellPoints[length - (i + 1)] = points[shellPointIndexes.top()];
        shellPointIndexes.pop();
    }

    int pointAIndex = 0;
    int pointBIndex = 0;
    for (int i = 0; i < length; i++)
        pointBIndex = shellPoints[i].y > shellPoints[pointBIndex].y ? i : pointBIndex;

    double distanceMax = 0.0;

    double calipersVectorX = 1.0;
    double calipersVectorY = 0.0;

    while (pointAIndex < length + 1 && pointBIndex < length + 1)
    {
        Vec2D deltaVector;
        deltaVector.x = shellPoints[pointBIndex % length].x - shellPoints[pointAIndex % length].x;
        deltaVector.y = shellPoints[pointBIndex % length].y - shellPoints[pointAIndex % length].y;
        distanceMax = max(distanceMax, sqrt(deltaVector.x * deltaVector.x + deltaVector.y * deltaVector.y));

        double edgeVectorAX, edgeVectorAY;
        double edgeVectorBX, edgeVectorBY;

        edgeVectorAX = shellPoints[(pointAIndex + 1) % length].x - shellPoints[pointAIndex % length].x;
        edgeVectorAY = shellPoints[(pointAIndex + 1) % length].y - shellPoints[pointAIndex % length].y;
        edgeVectorBX = shellPoints[(pointBIndex + 1) % length].x - shellPoints[pointBIndex % length].x;
        edgeVectorBY = shellPoints[(pointBIndex + 1) % length].y - shellPoints[pointBIndex % length].y;

        normalize(edgeVectorAX, edgeVectorAY);
        normalize(edgeVectorBX, edgeVectorBY);

        if (abs(calipersVectorX * edgeVectorAX + calipersVectorY * edgeVectorAY) > abs(calipersVectorX * edgeVectorBX + calipersVectorY * edgeVectorBY))
        {
            pointAIndex++;
            calipersVectorX = edgeVectorAX;
            calipersVectorY = edgeVectorAY;
        }
        else
        {
            pointBIndex++;
            calipersVectorX = edgeVectorBX;
            calipersVectorY = edgeVectorBY;
        }
    }

    delete[] shellPoints;

    return distanceMax;
}

int main()
{
    int t;
    cin >> t;

    Vec2D* points = new Vec2D[t];

    for (int i = 0; i < t; i++)
        cin >> points[i].x >> points[i].y;

    double distanceMax = maxDistance(points, t);

    cout.precision(11);
    cout << distanceMax;

    delete[] points;

    return 0;
}