#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

struct Vector2D
{
    int x;
    int y;
    int index;
    double angle;
};

bool compare(const Vector2D& a, const Vector2D& b)
{
    if (a.angle != b.angle)
        return a.angle < b.angle;
    else
        return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        Vector2D* points = new Vector2D[n];

        for (int j = 0; j < n; j++)
        {
            cin >> points[j].x >> points[j].y;
            points[j].index = j;
        }

        Vector2D bottomPoint = points[0];

        for (int j = 1; j < n; j++)
            bottomPoint = points[j].y < bottomPoint.y ? points[j] : bottomPoint;

        for (int j = 0; j < n; j++)
        {
            points[j].angle = atan2(points[j].y - bottomPoint.y, points[j].x - bottomPoint.x);
            points[j].x -= bottomPoint.x;
            points[j].y -= bottomPoint.y;
        }

        std::sort(points, points + n, compare);

        int k = n - 1;
        while (k > 0 && points[k - 1].angle == points[n - 1].angle)
            k--;

        for (int j = 0; k + j < n - j - 1; j++)
        {
            Vector2D temp = points[k + j];
            points[k + j] = points[n - j - 1];
            points[n - j - 1] = temp;
        }

        for (int j = 0; j < n; j++)
            cout << points[j].index << ' ';
        cout << endl;

        delete[] points;
    }

    return 0;
}