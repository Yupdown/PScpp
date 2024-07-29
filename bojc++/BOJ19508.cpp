#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

constexpr double EPS = 1e-9;

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
struct vector3d
{
	T x, y, z;

	vector3d() : vector3d(0, 0, 0) {}
	vector3d(T x, T y, T z) : x(x), y(y), z(z) {}
	template <typename TR>
	vector3d(const vector3d<TR>& rhs) : x(static_cast<T>(rhs.x)), y(static_cast<T>(rhs.y)), z(static_cast<T>(rhs.z)) {}

	vector3d operator-() const { return { -x, -y, -z }; };
	vector3d operator+(const vector3d& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z }; };
	vector3d operator-(const vector3d& rhs) const { return *this + (-rhs); };
	vector3d operator*(const T& rhs) const { return { x * rhs, y * rhs, z * rhs }; };
	vector3d operator/(const T& rhs) const { return { x / rhs, y / rhs, z / rhs }; };
	bool operator==(const vector3d& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; };
	bool operator!=(const vector3d& rhs) const { return !(*this == rhs); };

	static T dot(const vector3d& lhs, const vector3d& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	static vector3d cross(const vector3d& lhs, const vector3d& rhs)
	{
		return { lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x };
	}

	double magnitude() const
	{
		return sqrt(sqr_magnitude());
	}

	T sqr_magnitude() const
	{
		return dot(*this, *this);
	}

	vector3d normalized() const
	{
		return *this / magnitude();
	}
};

using int64 = long long;
using vector3di = vector3d<int64>;
using vector3df = vector3d<double>;

template <typename T>
inline T dot_product(const vector2d<T>& lhs, const vector2d<T>& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

template <typename T>
inline T cross_product(const vector2d<T>& lhs, const vector2d<T>& rhs)
{
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

using t_line = pair<vector2d<double>, vector2d<double>>;

bool parallel(int lhs, int rhs, t_line* p)
{
	return fabs(cross_product(p[lhs].second, p[rhs].second)) < EPS;
}

vector2d<double> intersection_point(int lhs, int rhs, t_line* p)
{
	double a11 = p[lhs].second.x;
	double a12 = -p[rhs].second.x;
	double a21 = p[lhs].second.y;
	double a22 = -p[rhs].second.y;
	double det = a11 * a22 - a12 * a21;
	double t = (a22 / det) * (p[rhs].first.x - p[lhs].first.x) - (a12 / det) * (p[rhs].first.y - p[lhs].first.y);
	return p[lhs].first + p[lhs].second * t;
}

double area_halfplanes(int n, t_line* p)
{
	sort(p, p + n, [](const t_line& lhs, const t_line& rhs) { return atan2(lhs.second.y, lhs.second.x) < atan2(rhs.second.y, rhs.second.x); });

	deque<int> dq;
	for (int i = 0; i < n; ++i)
	{
		while (dq.size() > 1)
		{
			int p1 = *(dq.end() - 2);
			int p2 = *(dq.end() - 1);
			auto v = intersection_point(p1, p2, p);
			if (cross_product(p[i].second, v - p[i].first) > -EPS)
				break;
			dq.pop_back();
		}

		while (dq.size() > 1)
		{
			int p1 = *(dq.begin());
			int p2 = *(dq.begin() + 1);
			auto v = intersection_point(p1, p2, p);
			if (cross_product(p[i].second, v - p[i].first) > -EPS)
				break;
			dq.pop_front();
		}

		if (dq.size() > 0 && parallel(dq.back(), i, p))
		{
			if (dot_product(p[dq.back()].second, p[i].second) < 0)
				return 0;
			if (cross_product(p[dq.back()].second, p[i].first - p[dq.back()].first) > -EPS)
				dq.pop_back();
			else
				continue;
		}

		dq.push_back(i);
	}

	while (dq.size() > 2)
	{
		int p1 = *(dq.end() - 2);
		int p2 = *(dq.end() - 1);
		auto v = intersection_point(p1, p2, p);
		if (cross_product(p[dq.front()].second, v - p[dq.front()].first) > -EPS)
			break;
		dq.pop_back();
	}

	while (dq.size() > 2)
	{
		int p1 = *(dq.begin());
		int p2 = *(dq.begin() + 1);
		auto v = intersection_point(p1, p2, p);
		if (cross_product(p[dq.back()].second, v - p[dq.back()].first) > -EPS)
			break;
		dq.pop_front();
	}

	if (dq.size() < 3)
		return 0.0;

	vector<vector2d<double>> points;
	points.push_back(intersection_point(dq.back(), dq.front(), p));
	for (auto iter = dq.begin(); iter != dq.end() - 1; ++iter)
		points.push_back(intersection_point(*iter, *(iter + 1), p));
	double ret = cross_product(points.back(), points.front());
	for (auto iter = points.begin() + 1; iter != points.end(); ++iter)
		ret += cross_product(*prev(iter), *iter);
	return abs(ret) * 0.5;
}

vector3di points[1000];

struct plane
{
	// points are alinged to clockwise
	int p1, p2, p3;

	plane(int p1, int p2, int p3) : p1(p1), p2(p2), p3(p3) {}

	int64 dot(const vector3di& p) const
	{
		vector3di normal = vector3di::cross(points[p3] - points[p1], points[p2] - points[p1]);
		return vector3di::dot(p - points[p1], normal);
	}

	int64 dot(int p) const
	{
		return dot(points[p]);
	}
};

vector<unique_ptr<plane>> planes;
plane* edges[1000][1000];

void quickhull(int n)
{
	// first, make a tetrahedron to depart the operation
	// the candidates of first, second are points[0], points[1] respectively.
	// begin to choose the third candidate, from points[2]
	int p2 = 2;
	while (p2 < n && vector3di::cross(points[1] - points[0], points[p2] - points[0]).sqr_magnitude() == 0)
		p2++;
	// all points are colinear
	if (p2 == n)
		return;
	planes.emplace_back(make_unique<plane>(0, 1, p2));

	// begin to choose the fourth candidate, from points[2]
	int p3 = 2;
	while (p3 < n && planes[0]->dot(p3) == 0)
		p3++;
	// all points are coplanar, returning one plane of the convex polygon
	if (p3 == n)
		return;

	planes.emplace_back(make_unique<plane>(0, 1, p3));
	planes.emplace_back(make_unique<plane>(0, p2, p3));
	planes.emplace_back(make_unique<plane>(1, p2, p3));

	if (planes[0]->dot(p3) > 0)
		swap(planes[0]->p2, planes[0]->p3);
	if (planes[1]->dot(p2) > 0)
		swap(planes[1]->p2, planes[1]->p3);
	if (planes[2]->dot(1) > 0)
		swap(planes[2]->p2, planes[2]->p3);
	if (planes[3]->dot(0) > 0)
		swap(planes[3]->p2, planes[3]->p3);

	for (const auto& pl : planes)
		edges[pl->p1][pl->p2] = edges[pl->p2][pl->p3] = edges[pl->p3][pl->p1] = pl.get();

	vector<int> outside_set;
	for (int i = 0; i < n; ++i)
	{
		if (any_of(planes.begin(), planes.end(), [i](const auto& pl) { return pl->dot(i) > 0; }))
			outside_set.push_back(i);
	}

	while (!outside_set.empty())
	{
		// select a point to make a new cone
		int p = outside_set.back();
		outside_set.pop_back();

		// calculate the visible set
		// find the conflict face of p
		plane* s0 = find_if(planes.begin(), planes.end(), [p](const auto& pl) { return pl->dot(p) > 0; })->get();

		// perform BFS to find the visible set and the horizon
		vector<pair<int, int>> horizon;
		set<plane*> flagged;
		queue<plane*> q;
		flagged.insert(s0);
		q.push(s0);

		while (!q.empty())
		{
			plane* s = q.front();
			q.pop();

			pair<int, int> edge_next[]{ { s->p1, s->p2 }, { s->p2, s->p3 }, { s->p3, s->p1 } };

			for (const auto& e : edge_next)
			{
				plane* pl = edges[e.second][e.first];
				if (flagged.find(pl) != flagged.end())
					continue;
				if (pl->dot(p) < 0)
				{
					horizon.emplace_back(e.first, e.second);
					continue;
				}
				q.push(pl);
				flagged.insert(pl);
			}
		}

		// remove all visible facets in planes
		auto dest = planes.begin();
		for (auto iter = planes.begin(); iter != planes.end(); ++iter)
		{
			if (flagged.find(iter->get()) == flagged.end())
				(*dest++).swap(*iter);
		}
		planes.erase(dest, planes.end());

		// add new facets filling the horizon
		for (const auto& h : horizon)
		{
			planes.emplace_back(make_unique<plane>(h.first, h.second, p));
			plane* pl = planes.back().get();
			edges[pl->p1][pl->p2] = edges[pl->p2][pl->p3] = edges[pl->p3][pl->p1] = pl;
		}

		while (!outside_set.empty() && all_of(planes.begin(), planes.end(), [&outside_set](const auto& pl) { return pl->dot(outside_set.back()) <= 0; }))
			outside_set.pop_back();
	}
}

double solution(int64 a, int64 b, int64 c, int64 d)
{
	vector3di nvi = vector3di(a, b, c);
	double m = nvi.magnitude();
	vector3df nv = vector3df(nvi) / m;
	vector3df pv = nv * -d / m;
	vector3df uv = vector3df(1, 0, 0);
	if (nv.x != 0 || nv.y != 0)
		uv = vector3df(nv.y, -nv.x, 0).normalized();
	vector3df vv = vector3df::cross(nv, uv);

	vector<t_line> lines;
	for (const auto& pl : planes)
	{
		vector3di nvpi = vector3di::cross(points[pl->p3] - points[pl->p1], points[pl->p2] - points[pl->p1]);
		// the planes are parallel against the each other
		if (vector3di::cross(nvi, nvpi).sqr_magnitude() == 0)
		{
			int64 o1 = vector3di::dot(nvi, points[pl->p1]) + d;
			int64 o2 = vector3di::dot(nvi, nvpi);
			if ((o1 < 0 && o2 > 0) || (o1 > 0 && o2 < 0))
				return 0;
			continue;
		}

		vector3df nvp = nvpi;
		vector3df uvp = vector3df(points[pl->p1]) - pv;
		nvp = vector3df(vector3df::dot(nvp, uv), vector3df::dot(nvp, vv), vector3df::dot(nvp, nv)).normalized();
		uvp = vector3df(vector3df::dot(uvp, uv), vector3df::dot(uvp, vv), vector3df::dot(uvp, nv));
		double dd = -vector3df::dot(nvp, uvp);

		vector3df nvp2 = vector3df(-nvp.x, -nvp.y, 0);
		double m = nvp2.magnitude();
		nvp2 = nvp2 / m;
		vector3df uvp2 = nvp2 * dd / m;

		lines.emplace_back(make_pair(vector2d<double>(uvp2.x, uvp2.y), vector2d<double>(nvp2.y, -nvp2.x)));
	}

	return area_halfplanes(lines.size(), lines.data());
}

template <typename T>
vector<vector2d<T>> monotone_chain(vector<vector2d<T>> points)
{
	size_t n = points.size(), k = 0;
	if (n <= 3)
		return points;

	sort(points.begin(), points.end());

	vector<vector2d<T>> out(n * 2);
	for (size_t i = 0; i < n; ++i)
	{
		while (k >= 2 && vector2d<T>::cross(out[k - 1] - out[k - 2], points[i] - out[k - 2]) <= 0)
			--k;
		out[k++] = points[i];
	}
	for (size_t i = n - 1, t = k + 1; i > 0; --i)
	{
		while (k >= t && vector2d<T>::cross(out[k - 1] - out[k - 2], points[i - 1] - out[k - 2]) <= 0)
			--k;
		out[k++] = points[i - 1];
	}

	out.resize(k - 1);
	return out;
}

int main()
{
	FASTIO();
	PRECISION(3);

	int n, q;
	cin >> n >> q;
	for (size_t i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y >> points[i].z;

	// the points may have duplicates, delete the duplicates
	sort(points, points + n, [](const vector3di& lhs, const vector3di& rhs) { if (lhs.x != rhs.x) return lhs.x < rhs.x; if (lhs.y != rhs.y) return lhs.y < rhs.y; return lhs.z < rhs.z; });
	size_t j = 1;
	for (size_t i = 1; i < n; ++i)
	{
		if (points[i - 1] != points[i])
			points[j++] = points[i];
	}
	n = j;
	if (n > 2)
		quickhull(n);

	// if the plane is just one, it means that all points are coplanar and these can create a 2D convex hull
	double hull_area = 0;
	if (planes.size() == 1)
	{
		auto pl = planes[0].get();
		vector3df nv = vector3di::cross(points[pl->p3] - points[pl->p1], points[pl->p2] - points[pl->p1]);
		nv = nv.normalized();
		vector3df uv = points[pl->p2] - points[pl->p1];
		uv = uv.normalized();
		vector3df vv = vector3df::cross(nv, uv);
		vector<vector2d<double>> projected_points(n);
		transform(points, points + n, projected_points.begin(), [&uv, &vv](const auto& v) { return vector2d<double>(vector3df::dot(v, uv), vector3df::dot(v, vv)); });
		vector<vector2d<double>> hull_points = monotone_chain(projected_points);
		hull_area = cross_product(hull_points.back(), hull_points.front());
		for (auto iter = hull_points.begin() + 1; iter != hull_points.end(); ++iter)
			hull_area += cross_product(*prev(iter), *iter);
		hull_area = abs(hull_area) * 0.5;
	}

	for (int i = 0; i < q; ++i)
	{
		int64 a, b, c, d;
		cin >> a >> b >> c >> d;
		if (planes.size() == 0)
			cout << 0 << '\n';
		else if (planes.size() == 1)
		{
			auto pl = planes[0].get();
			vector3di nvi = vector3di(a, b, c);
			vector3df nvpi = vector3di::cross(points[pl->p3] - points[pl->p1], points[pl->p2] - points[pl->p1]);
			cout << (vector3di::dot(points[pl->p1], nvi) + d == 0 && vector3di::cross(nvi, nvpi).sqr_magnitude() == 0 ? hull_area : 0) << '\n';
		}
		else
			cout << solution(a, b, c, d) << '\n';
	}
}