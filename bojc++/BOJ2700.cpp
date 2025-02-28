#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

struct vector2d
{
    int x;
    int y;
};

struct result_container
{
    int y;
    int xmin;
    int xmax;
};

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

bool included_convexhull(vector2d* convexhull, int n, vector2d p)
{
    for (int i = 0; i < n; ++i)
    {
        vector2d p0 = convexhull[i];
        vector2d p1 = convexhull[(i + 1) % n];

        if (orientation(p0, p1, p) <= 0)
            return false;
    }

    return true;
}

int main()
{
    FASTIO();

    vector2d points[50];
    vector<result_container> result;

    int p;
    cin >> p;

    while (p-- > 0)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> points[i].x >> points[i].y;

        int xmin, xmax, ymin, ymax;
        xmin = xmax = points[0].x;
        ymin = ymax = points[0].y;

        for (int i = 0; i < n; ++i)
        {
            xmin = min(xmin, points[i].x);
            xmax = max(xmax, points[i].x);
            ymin = min(ymin, points[i].y);
            ymax = max(ymax, points[i].y);
        }

        for (int y = ymax - 1; y > ymin; --y)
        {
            int vmin = xmax;
            int vmax = xmin;
            bool flag = false;

            for (int x = xmin + 1; x < xmax; ++x)
            {
                if (included_convexhull(points, n, { x, y }))
                {
                    vmin = min(vmin, x);
                    vmax = max(vmax, x);
                    flag = true;
                }
                else if (flag)
                    break;
            }

            if (vmin <= vmax)
                result.push_back({ y, vmin, vmax });
        }

        cout << result.size() << '\n';
        for (auto iter : result)
            cout << iter.y << ' ' << iter.xmin << ' ' << iter.xmax << '\n';
        result.clear();
    }

    return 0;
}