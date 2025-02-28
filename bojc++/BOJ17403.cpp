#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

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
    return sortedPoints;
}

inline int serialize_vector2d(const vector2d& v)
{
    return v.x + 20001 * v.y;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, np, c = 0;
    vector2d p, w[1000], wp[1000];
    map<int, int> r;
    cin >> n;
    np = n;

    for (int i = 0; i < n; ++i)
    {
        cin >> w[i].x >> w[i].y;
        wp[i] = w[i];
    }

    vector<vector2d> convexhull;
    while (np > 2)
    {
        convexhull = get_convexhull(wp, np);
        if (convexhull.size() < 3)
            break;

        c++;
        for (int i = 0; i < convexhull.size(); ++i)
            r.insert({ serialize_vector2d(convexhull[i]), c });

        for (int i = 0, j = 0; i < np; ++i)
        {
            bool duplicate = false;
            for (int k = 0; k < convexhull.size(); ++k)
            {
                if (wp[i].x == convexhull[k].x && wp[i].y == convexhull[k].y)
                {
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate)
                wp[j++] = wp[i];
        }
        np -= convexhull.size();
    }

    for (int i = 0; i < n; ++i)
    {
        auto iter = r.find(serialize_vector2d(w[i]));

        if (iter != r.end())
            cout << iter->second;
        else
            cout << 0;
        cout << (i < n - 1 ? ' ' : '\n');
    }

    return 0;
}