#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

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

int64 sqr_magnitude(vector2d v)
{
    return v.x * v.x + v.y * v.y;
}

vector<vector2d> get_convexhull(vector2d* points, int size)
{
    int pivot = 0;
    for (int i = 1; i < size; i++)
        pivot = (points[i].x == points[pivot].x ? points[i].y < points[pivot].y : points[i].x < points[pivot].x) ? i : pivot;

    std::swap(points[0], points[pivot]);
    std::sort(points + 1, points + size, [=](const vector2d& a, const vector2d& b) -> bool
        {
            int orient = orientation(points[0], a, b);
            if (orient != 0)
                return orient < 0;
            return sqr_magnitude((vector2d)a - points[0]) < sqr_magnitude((vector2d)b - points[0]);
        });

    vector<vector2d> sortedPoints;
    sortedPoints.push_back(points[0]);

    for (int i = 1; i < size; i++)
    {
        if (i < size - 1)
        {
            if (orientation(points[0], points[i], points[i + 1]) == 0)
                continue;
        }
        sortedPoints.push_back(points[i]);
    }

    size = sortedPoints.size();

    if (size > 2)
    {
        int first = 0, second = 0, next = 1;
        stack<int> graham_scan;
        graham_scan.push(0);

        while (next < size)
        {
            first = second;
            second = next++;
            while (orientation(sortedPoints[first], sortedPoints[second], sortedPoints[next % size]) >= 0)
            {
                second = first;
                graham_scan.pop();
                first = graham_scan.top();
            }
            graham_scan.push(second);
        }

        int length = graham_scan.size();
        vector<vector2d> shellPoints = vector<vector2d>(length);

        for (int i = 0; i < length; i++)
        {
            shellPoints[length - i - 1] = sortedPoints[graham_scan.top()];
            graham_scan.pop();
        }

        return shellPoints;
    }
    else
        return sortedPoints;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cout.precision(2);
    cout << fixed;
    ios::sync_with_stdio(false);

    int count = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector2d points[100];
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        vector<vector2d> convexhull = get_convexhull(points, n);
        int size = convexhull.size();

        double result = 100000.0;
        for (int i = 0; i < size; i++)
        {
            double distance_max = 0.0;
            for (int j = 0; j < size; j++)
            {
                if (j == i || j == (i + 1) % size)
                    continue;
                vector2d p0 = convexhull[j];
                vector2d p1 = convexhull[i];
                vector2d p2 = convexhull[(i + 1) % size];
                double distance = (double)abs((p2.x - p1.x) * (p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p1.y)) / sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
                distance_max = max(distance_max, distance);
            }
            result = min(result, distance_max);
        }

        cout << "Case " << ++count << ": " << ceil(result * 100.0) / 100.0 << endl;
    }

    return 0;
}