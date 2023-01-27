#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

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

    vector2d operator+(const vector2d& other) const
    {
        return vector2d(x + other.x, y + other.y);
    }

    vector2d operator-(const vector2d& other) const
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

inline double get_distance(const vector2d& p1, const vector2d& p2, const vector2d& p3)
{
    vector2d dv = p2 - p1;
    return abs<double>(dv.x * (p1.y - p3.y) - dv.y * (p1.x - p3.x)) / sqrt(dv.x * dv.x + dv.y * dv.y);
}

double rotating_calipers(vector2d* points, int size)
{
    double dist_min = 200'000'000;
    vector2d zeroVector = vector2d();
    int j = 1;

    for (int i = 0; i < size; i++)
    {
        int iNext = (i + 1) % size;
        vector2d iVector = points[iNext] - points[i];

        do
        {
            int jNext = (j + 1) % size;
            vector2d jVector = points[jNext] - points[j];

            if (orientation(zeroVector, iVector, jVector) < 0)
                j = jNext;
            else
                break;
        } while (true);

        dist_min = min(dist_min, get_distance(points[i], points[iNext], points[j]));
    }

    return dist_min;
}

vector2d points[200000];

int main()
{
    FASTIO();
    PRECISION(16);

    int n, r;
    cin >> n >> r;

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<vector2d> convexhull = get_convexhull(points, n);
    int size = convexhull.size();

    double result;
    if (size > 2)
        result = rotating_calipers(convexhull.data(), size);
    else
        result = 0;

    cout << result;
    return 0;
}