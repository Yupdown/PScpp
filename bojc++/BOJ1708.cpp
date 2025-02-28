#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

typedef struct
{
    double x;
    double y;
    double angle;
}vector2d;

int compare(const void* a, const void* b)
{
    vector2d pointA = (*(vector2d*)a);
    vector2d pointB = (*(vector2d*)b);

    if (pointA.angle != pointB.angle)
        return pointA.angle > pointB.angle ? 1 : -1;
    else if (pointA.y != pointB.y)
        return pointA.y > pointB.y ? 1 : -1;
    else
        return pointA.x > pointB.x ? 1 : -1;
}

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

double get_result(vector2d* points, int size)
{
    vector2d bottomPoint = points[0];

    for (int i = 1; i < size; i++)
        bottomPoint = points[i].y < bottomPoint.y || (points[i].y == bottomPoint.y && points[i].x < bottomPoint.x) ? points[i] : bottomPoint;

    for (int i = 0; i < size; i++)
        points[i].angle = atan2(points[i].y - bottomPoint.y, points[i].x - bottomPoint.x);

    qsort(points, size, sizeof(vector2d), compare);

    int first = 0, second = 0, next = 1;
    stack<int> shellPointIndexes;
    shellPointIndexes.push(0);

    while (orientation(points[0], points[next], points[(next + 1) % size]) >= 0)
    {
        next++;

        if (!(next < size))
        {
            vector2d deltaVector;
            deltaVector.x = points[size - 1].x - points[0].x;
            deltaVector.y = points[size - 1].y - points[0].y;

            return sqrt(deltaVector.x * deltaVector.x + deltaVector.y * deltaVector.y);
        }
    }

    while (next < size)
    {
        first = second;
        second = next++;
        while (orientation(points[first], points[second], points[next % size]) >= 0)
        {
            second = first;
            shellPointIndexes.pop();
            first = shellPointIndexes.top();
        }
        shellPointIndexes.push(second);
    }

    return shellPointIndexes.size();
}

int main()
{
    int t;
    cin >> t;

    vector2d* points = new vector2d[t];

    for (int i = 0; i < t; i++)
        cin >> points[i].x >> points[i].y;

    cout << get_result(points, t) << endl;
    delete[] points;

    return 0;
}