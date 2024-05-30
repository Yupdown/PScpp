#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

struct vector2d
{
    int64 x;
    int64 y;

    vector2d() : vector2d(0LL, 0LL) {}
    vector2d(int64 x, int64 y) : x(x), y(y) {}

    vector2d operator+(const vector2d& other) const { return vector2d(x + other.x, y + other.y); }
    vector2d operator-(const vector2d& other) const { return vector2d(x - other.x, y - other.y); }
    vector2d operator+() const { return vector2d(x, y); }
    vector2d operator-() const { return vector2d(-x, -y); }
    vector2d operator*(const int64& scalar) const { return vector2d(x * scalar, y * scalar); }
    vector2d operator/(const int64& scalar) const { return vector2d(x / scalar, y / scalar); }
    vector2d& operator+=(const vector2d& other) { x += other.x; y += other.y; return *this; }
    vector2d& operator-=(const vector2d& other) { x -= other.x; y -= other.y; return *this; }
    vector2d& operator*=(const int64& scalar) { x *= scalar; y *= scalar; return *this; }
    vector2d& operator/=(const int64& scalar) { x /= scalar; y /= scalar; return *this; }
    bool operator==(const vector2d& other) const { return x == other.x && y == other.y; }
    bool operator!=(const vector2d& other) const { return x != other.x || y != other.y; }
    bool operator<(const vector2d& other) const { return x < other.x || (x == other.x && y < other.y); }
    bool operator>(const vector2d& other) const { return x > other.x || (x == other.x && y > other.y); }
    bool operator<=(const vector2d& other) const { return x <= other.x && y <= other.y; }
    bool operator>=(const vector2d& other) const { return x >= other.x && y >= other.y; }
    friend std::ostream& operator<<(std::ostream& os, const vector2d& v) { os << "(" << v.x << ", " << v.y << ")"; return os; }
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

inline int64 cross_product(const vector2d& lhs, const vector2d& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
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

vector2d points[1000];

int64 ternary_search(const vector<vector2d>& v, int n, int from, int to)
{
    vector2d d = v[to] - v[from];
    vector2d vp = v[from];
    int64 dp = 0, dq;

    if (to < from)
        to += n;

    while (to - from > 2)
    {
        int p = (from * 2 + to) / 3;
        int q = (from + to * 2) / 3;

        dp = abs(cross_product(d, v[from % n] - vp));
        dq = abs(cross_product(d, v[to % n] - vp));

        if (dp < dq)
            from = p;
        else
            to = q;
    }
    for (int i = from; i <= to; ++i)
        dp = max(dp, abs(cross_product(d, v[i % n] - vp)));

    return dp;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> points[i].x >> points[i].y;

        auto shell = graham_scan(points, n);
        n = shell.size();

        int64 smax = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
                smax = max(smax, ternary_search(shell, n, i, j) + ternary_search(shell, n, j, i));
        }

        cout << smax / 2 << (smax & 1 ? ".5\n" : "\n");
	}
}