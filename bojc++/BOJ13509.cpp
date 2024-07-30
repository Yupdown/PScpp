#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

template <typename T>
struct vector2d
{
    T x, y;

    vector2d() : vector2d(0, 0) {}
    vector2d(T x, T y) : x(x), y(y) {}

    bool operator<(const vector2d& other) const { return x < other.x || (x == other.x && y < other.y); }
};

using vector2di = vector2d<int>;

map<vector2di, int> solution(vector<vector2di> points)
{
    const int sn = 1 << 19;
    const int pv = sn >> 1;
    vector<int> sg(sn, INT_MIN);

    set<int> ymap;
    for (const auto& p : points)
        ymap.insert(p.y);
    vector<int> vymap(ymap.begin(), ymap.end());
    sort(points.begin(), points.end());

    map<vector2di, int> ret;
    for (const auto& point : points)
    {
        auto sp = distance(vymap.begin(), lower_bound(vymap.begin(), vymap.end(), point.y));
        int vmax = sg[pv + sp];
        for (int i = pv + sp; i > 0; i >>= 1)
        {
            if (i & 1)
                vmax = max(vmax, sg[i - 1]);
            sg[i] = max(sg[i], point.x + point.y);
        }
        ret[point] = vmax != INT_MIN ? abs(point.x + point.y - vmax) : INT_MAX;
    }

    return ret;
}

vector2di convert(const vector2di& p, int i)
{
    vector2di mul = vector2di("2200"[i] - '1', "2020"[i] - '1');
    return vector2di(p.x * mul.x, p.y * mul.y);
}

int main()
{
	FASTIO();

    int n;
    cin >> n;

    vector<vector2di> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;
    vector<int> ret(n, INT_MAX);

    vector<vector2di> points_converted(n);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < n; ++j)
            points_converted[j] = convert(points[j], i);
        auto m = solution(points_converted);
        for (int j = 0; j < n; ++j)
            ret[j] = min(ret[j], m[convert(points[j], i)]);
    }

    for (int i = 0; i < n; ++i)
        cout << ret[i] << '\n';
}