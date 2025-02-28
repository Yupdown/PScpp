#include <iostream>
#include <algorithm>
#include <vector>
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

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    vector<pair<vector2d, double>> points;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        vector2d p;
        char c;
        cin >> p.x >> p.y >> c;

        if (c == 'Y')
            points.push_back({ p, 0.0 });
    }

    n = points.size();
    int pivot = 0;
    for (int i = 1; i < n; ++i)
    {
        vector2d a = points[i].first;
        vector2d b = points[pivot].first;

        pivot = (a.x == b.x ? a.y < b.y : a.x < b.x) ? i : pivot;
    }

    std::swap(points[0], points[pivot]);
    for (int i = 1; i < n; ++i)
    {
        vector2d a = points[i].first;
        vector2d b = points[0].first;

        points[i].second = atan2(a.y - b.y, a.x - b.x);
    }

    std::sort(points.begin() + 1, points.end(), [](const pair<vector2d, double>& a, const pair<vector2d, double>& b) -> bool { return a.second < b.second; });

    vector2d origin = points[0].first;
    auto iter_a = points.begin() + 1;
    while (points[1].second == (*iter_a).second && iter_a != points.end())
        iter_a++;
    auto iter_b = points.begin() + 1;
    while (points[n - 1].second != (*iter_b).second && iter_b != points.end())
        iter_b++;

    std::sort(points.begin() + 1, iter_a, [=](const pair<vector2d, double>& a, const pair<vector2d, double>& b) -> bool { return sqr_magnitude((vector2d)a.first - origin) < sqr_magnitude((vector2d)b.first - origin); });
    std::sort(iter_b, points.end(), [=](const pair<vector2d, double>& a, const pair<vector2d, double>& b) -> bool { return sqr_magnitude((vector2d)a.first - origin) > sqr_magnitude((vector2d)b.first - origin); });

    cout << n << '\n';
    for (int i = 0; i < n; ++i)
        cout << points[i].first.x << ' ' << points[i].first.y << '\n';

    return 0;
}