#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

template <typename T>
struct vector2d
{
    T x, y;

    vector2d() : vector2d(0, 0) {}
    vector2d(T x, T y) : x(x), y(y) {}
    vector2d(const vector2d& rhs) : x(rhs.x), y(rhs.y) {}
    template <typename TR>
    vector2d(const vector2d<TR>& rhs) : x(static_cast<T>(rhs.x)), y(static_cast<T>(rhs.y)) {}

    T sqr_magnitude() const { return x * x + y * y; }
    T magnitude() const { return sqrt(sqr_magnitude()); }
    static T dot(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
    static T cross(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }

    vector2d operator+(const vector2d& other) const { return vector2d(x + other.x, y + other.y); }
    vector2d operator-(const vector2d& other) const { return vector2d(x - other.x, y - other.y); }
    vector2d operator+() const { return vector2d(x, y); }
    vector2d operator-() const { return vector2d(-x, -y); }
    vector2d operator*(const T& scalar) const { return vector2d(x * scalar, y * scalar); }
    vector2d operator/(const T& scalar) const { return vector2d(x / scalar, y / scalar); }
    vector2d& operator+=(const vector2d& other) { x += other.x; y += other.y; return *this; }
    vector2d& operator-=(const vector2d& other) { x -= other.x; y -= other.y; return *this; }
    vector2d& operator*=(const T& scalar) { x *= scalar; y *= scalar; return *this; }
    vector2d& operator/=(const T& scalar) { x /= scalar; y /= scalar; return *this; }
    bool operator==(const vector2d& other) const { return x == other.x && y == other.y; }
    bool operator!=(const vector2d& other) const { return x != other.x || y != other.y; }
    bool operator<(const vector2d& other) const { return x < other.x || (x == other.x && y < other.y); }
    bool operator>(const vector2d& other) const { return x > other.x || (x == other.x && y > other.y); }
    bool operator<=(const vector2d& other) const { return x <= other.x && y <= other.y; }
    bool operator>=(const vector2d& other) const { return x >= other.x && y >= other.y; }
};

template <typename T>
bool circumcenter_contains(const vector2d<T>& a, const vector2d<T>& b, const vector2d<T>& c, const vector2d<T>& p)
{
    vector2d<T> da = a - p;
    vector2d<T> db = b - p;
    vector2d<T> dc = c - p;
    
    T la = da.sqr_magnitude();
    T lb = db.sqr_magnitude();
    T lc = dc.sqr_magnitude();

    T det = (da.x * db.y * lc + da.y * lb * dc.x + la * db.x * dc.y)
          - (la * db.y * dc.x + da.x * lb * dc.y + da.y * db.x * lc);
    return det < 0;
}

class triangulation_graph
{
public:
    struct edge
    {
        size_t from = 0;
        size_t to = 0;
        edge* next = nullptr;
        edge* prev = nullptr;
        edge* sym = nullptr;
        bool flag = false;
    };

    edge* make_edge(size_t from, size_t to)
    {
        edges.emplace_back(make_unique<edge>());
        edges.emplace_back(make_unique<edge>());

        edge* e = edges.end()[-2].get();
        edge* es = edges.end()[-1].get();

        e->from = from;
        e->to = to;
        e->next = e;
        e->prev = e;
        e->sym = es;

        es->from = to;
        es->to = from;
        es->next = es;
        es->prev = es;
        es->sym = e;

        return e;
    }

    void splice(edge* lhs, edge* rhs)
    {
        if (lhs == rhs)
            return;

        lhs->next->prev = rhs;
        rhs->next->prev = lhs;
        swap(lhs->next, rhs->next);
    }

    edge* connect(edge* lhs, edge* rhs)
    {
        edge* e = make_edge(lhs->to, rhs->from);

        splice(e, lhs->sym->prev);
        splice(e->sym, rhs);

        return e;
    }

    void delete_edge(edge* e)
    {
        splice(e, e->prev);
        splice(e->sym, e->sym->prev);

        e->flag = true;
        e->sym->flag = true;
    }

    void populate_edges(vector<vector<size_t>>& out)
    {
        for (const auto& e : edges)
        {
            if (e->flag)
                continue;
            out[e->from].push_back(e->to);
        }
    }

private:
    vector<unique_ptr<edge>> edges;
};

template <typename T>
pair<triangulation_graph::edge*, triangulation_graph::edge*> delaunay_internal(const vector<vector2d<T>>& points, triangulation_graph& graph, size_t from, size_t to)
{
    if (to - from == 2)
    {
        auto e = graph.make_edge(from, to - 1);
        return make_pair(e, e->sym);
    }
    if (to - from == 3)
    {
        size_t p1 = from;
        size_t p2 = from + 1;
        size_t p3 = from + 2;

        auto e1 = graph.make_edge(p1, p2);
        auto e2 = graph.make_edge(p2, p3);
        graph.splice(e1->sym, e2);

        T product = vector2d<T>::cross(points[p2] - points[p1], points[p3] - points[p1]);
        if (product > 0)
        {
            graph.connect(e2, e1);
            return make_pair(e1, e2->sym);
        }
        else if (product < 0)
        {
            auto e3 = graph.connect(e2, e1);
            return make_pair(e3->sym, e3);
        }
        else
            return make_pair(e1, e2->sym);
    }

    size_t mid = (from + to) / 2;
    auto [ldo, ldi] = delaunay_internal(points, graph, from, mid);
    auto [rdi, rdo] = delaunay_internal(points, graph, mid, to);

    while (true)
    {
        if (vector2d<T>::cross(points[ldi->to] - points[ldi->from], points[rdi->from] - points[ldi->from]) > 0)
            ldi = ldi->sym->next;
        else if (vector2d<T>::cross(points[rdi->to] - points[rdi->from], points[ldi->from] - points[rdi->from]) < 0)
            rdi = rdi->sym->prev;
        else
            break;
    }

    auto base = graph.connect(ldi->sym, rdi);

    if (ldi->from == ldo->from)
        ldo = base;
    if (rdi->from == rdo->from)
        rdo = base->sym;

    while (true)
    {
        auto rcand = base->sym->next;
        auto lcand = base->prev;

        bool rvalid = vector2d<T>::cross(points[base->to] - points[base->from], points[rcand->to] - points[base->from]) > 0;
        bool lvalid = vector2d<T>::cross(points[base->to] - points[base->from], points[lcand->to] - points[base->from]) > 0;

        if (!rvalid && !lvalid)
            break;

        if (rvalid)
        {
            while (vector2d<T>::cross(points[base->to] - points[base->from], points[rcand->next->to] - points[base->from]) > 0 &&
                circumcenter_contains(points[base->to], points[base->from], points[rcand->to], points[rcand->next->to]))
            {
                auto t = rcand->next;
                graph.delete_edge(rcand);
                rcand = t;
            }
        }

        if (lvalid)
        {
            while (vector2d<T>::cross(points[base->to] - points[base->from], points[lcand->prev->to] - points[base->from]) > 0 &&
                circumcenter_contains(points[base->to], points[base->from], points[lcand->to], points[lcand->prev->to]))
            {
                auto t = lcand->prev;
                graph.delete_edge(lcand);
                lcand = t;
            }
        }

        if (!rvalid || (lvalid && circumcenter_contains(points[rcand->to], points[rcand->from], points[lcand->from], points[lcand->to])))
            base = graph.connect(lcand, base->sym);
        else
            base = graph.connect(base->sym, rcand->sym);
    }

    return make_pair(ldo, rdo);
}

// the parameter points must be sorted in x-y increasing order.
template <typename T>
vector<vector<size_t>> delaunay(const vector<vector2d<T>>& points)
{
    size_t n = points.size();
    triangulation_graph graph;
    delaunay_internal(points, graph, 0, n);
    vector<vector<size_t>> edges(n);
    graph.populate_edges(edges);
    return edges;
}

using vector2di = vector2d<long long>;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

        vector<tuple<size_t, vector2di, long long>> points(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> get<1>(points[i]).x >> get<1>(points[i]).y;
            get<0>(points[i]) = i;
        }

        sort(points.begin(), points.end(), [](const auto& lhs, const auto& rhs) { return get<1>(lhs) < get<1>(rhs); });
        vector<vector2di> serialized(n);
        transform(points.begin(), points.end(), serialized.begin(), [](const auto& v) { return get<1>(v); });
        vector<vector<size_t>> adj = delaunay(serialized);

        for (int i = 0; i < n; ++i)
        {
            auto dmin = LLONG_MAX;
            for (int j : adj[i])
                dmin = min(dmin, (get<1>(points[i]) - get<1>(points[j])).sqr_magnitude());
            get<2>(points[i]) = dmin;
        }

        sort(points.begin(), points.end());
        for (int i = 0; i < n; ++i)
            cout << get<2>(points[i]) << '\n';
	}
}