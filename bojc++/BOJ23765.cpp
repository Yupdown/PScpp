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

inline int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : (result < 0 ? -1 : 0);
}

inline int64 sqr_magnitude(const vector2d& v)
{
    return v.x * v.x + v.y * v.y;
}

inline int64 cross_magnitude(const vector2d& p1, const vector2d& p2, const vector2d& p3)
{
    return abs((p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.x * p3.y + p2.x * p1.y + p3.x * p2.y));
}

vector<vector2d> graham_scan(vector2d* points, int size)
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
        stack<int> scan;
        scan.push(0);

        while (next < size)
        {
            first = second;
            second = next++;
            while (orientation(sortedPoints[first], sortedPoints[second], sortedPoints[next % size]) >= 0)
            {
                second = first;
                scan.pop();
                first = scan.top();
            }
            scan.push(second);
        }

        int length = scan.size();
        vector<vector2d> shellPoints = vector<vector2d>(length);

        for (int i = 0; i < length; i++)
        {
            shellPoints[length - i - 1] = sortedPoints[scan.top()];
            scan.pop();
        }

        return shellPoints;
    }
    return sortedPoints;
}

vector2d point[400];
int64 memo[400][400][10];

int main()
{
    FASTIO();
    PRECISION(1);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> point[i].x >> point[i].y;

    vector<vector2d> hull_points = graham_scan(point, n);
    int m = hull_points.size();

    int c = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            for (int k = j + 1; k < m; ++k)
            {
                int64 magnitude = cross_magnitude(hull_points[i], hull_points[j], hull_points[k]);

                memo[i][j][0] = max(memo[i][j][0], magnitude);
                memo[j][k][0] = max(memo[j][k][0], magnitude);
                memo[k][i][0] = max(memo[k][i][0], magnitude);

                ++c;
            }
        }
    }

    for (int l = 1; l < k - 2; ++l)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == j)
                    continue;

                int lhs = i;
                int rhs = j > i ? j : j + m;

                ++c;

                /*for (int mid = lhs + 1; mid < rhs; ++mid)
                {
                    int64 magnitude = cross_magnitude(hull_points[i], hull_points[mid % m], hull_points[j]);
                    memo[i][j][l] = max(memo[i][j][l], max(memo[i][mid % m][l - 1], memo[mid % m][j][l - 1]) + magnitude);

                    ++c;
                }*/
            }
        }
    }

    int64 vmax = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
            vmax = max(vmax, memo[i][j][k - 3]);
    }

    cout << c << " " << 0.5 * vmax << endl;
}

int N, points[400][2];
int dp[400][14];

int calc_area(int i, int count)
{
    if (count >= 3)
    {
        int x1 = points[i][0];
        int y1 = points[i][1];
        int x2 = points[i - 1][0];
        int y2 = points[i - 1][1];
        int x3 = points[i - 2][0];
        int y3 = points[i - 2][1];

        return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
    }
    return 0;
}

int solve(int i, int count)
{
    if (count > 12)
        return -1e9; // -1,000,000,000
    if (i == N)
        return 0;
    if (dp[i][count] != -1)
        return dp[i][count];

    int area = calc_area(i, count);
    int ret = max(solve(i + 1, count), solve(i + 1, count + 1) + area);

    dp[i][count] = ret;

    return ret;
}
