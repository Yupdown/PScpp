#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

struct vector2d { double x, y; };
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

	T magnitude() const
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

using vector3di = vector3d<long long>;
using vector3df = vector3d<double>;

vector3di points[1000];

struct plane
{
	// points are alinged to clockwise
	int p1, p2, p3;

	plane(int p1, int p2, int p3) : p1(p1), p2(p2), p3(p3) {}

	bool above(const vector3di& p) const
	{
		vector3di normal = vector3di::cross(points[p3] - points[p1], points[p2] - points[p1]);
		return vector3di::dot(p - points[p1], normal) > 0;
	}

	bool above(int p) const
	{
		return above(points[p]);
	}
};

vector<unique_ptr<plane>> planes;
plane* edges[1000][1000];

void quickhull(int n)
{
	// first, make a tetrahedron to depart the operation
	planes.emplace_back(make_unique<plane>(0, 1, 2));
	planes.emplace_back(make_unique<plane>(0, 1, 3));
	planes.emplace_back(make_unique<plane>(0, 2, 3));
	planes.emplace_back(make_unique<plane>(1, 2, 3));

	if (planes[0]->above(3))
		swap(planes[0]->p2, planes[0]->p3);
	if (planes[1]->above(2))
		swap(planes[1]->p2, planes[1]->p3);
	if (planes[2]->above(1))
		swap(planes[2]->p2, planes[2]->p3);
	if (planes[3]->above(0))
		swap(planes[3]->p2, planes[3]->p3);

	for (const auto& pl : planes)
		edges[pl->p1][pl->p2] = edges[pl->p2][pl->p3] = edges[pl->p3][pl->p1] = pl.get();
	
	vector<int> outside_set;
	for (int i = 4; i < n; ++i)
	{
		if (any_of(planes.begin(), planes.end(), [i](const auto& pl) { return pl->above(i); }))
			outside_set.push_back(i);
	}

	while (!outside_set.empty())
	{
		// select a point to make a new cone
		int p = outside_set.back();
		outside_set.pop_back();

		// calculate the visible set
		// find the conflict face of p
		plane* s0 = find_if(planes.begin(), planes.end(), [p](const auto& pl) { return pl->above(p); })->get();

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
				if (!pl->above(p))
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

		while (!outside_set.empty() && all_of(planes.begin(), planes.end(), [&outside_set](const auto& pl) { return !pl->above(outside_set.back()); }))
			outside_set.pop_back();
	}
}

vector2d circumcenter(const vector2d& a, const vector2d& b, const vector2d& c)
{
	double ax = a.x - c.x;
	double ay = a.y - c.y;
	double bx = b.x - c.x;
	double by = b.y - c.y;

	double asq = ax * ax + ay * ay;
	double bsq = bx * bx + by * by;
	double ccw = ax * by - ay * bx;

	return vector2d{
		c.x + (by * asq - ay * bsq) / (ccw * 2),
		c.y + (-bx * asq + ax * bsq) / (ccw * 2)
	};
}

double sqr_dist(const vector2d& lhs, const vector2d& rhs)
{
	vector2d dv = vector2d{ lhs.x - rhs.x, lhs.y - rhs.y };
	return dv.x * dv.x + dv.y * dv.y;
}

double solution(const vector<vector2d>& points)
{
	int n = points.size();
	vector2d p{};
	double rr = 0;

	for (int i = 0; i < n; ++i)
	{
		if (sqr_dist(p, points[i]) > rr)
		{
			p = points[i];
			rr = 0;
			for (int j = 0; j < i; ++j)
			{
				if (sqr_dist(p, points[j]) > rr)
				{
					p = vector2d{ (points[i].x + points[j].x) / 2, (points[i].y + points[j].y) / 2 };
					rr = sqr_dist(p, points[i]);
					for (int k = 0; k < j; ++k)
					{
						if (sqr_dist(p, points[k]) > rr)
						{
							p = circumcenter(points[i], points[j], points[k]);
							rr = sqr_dist(p, points[i]);
						}
					}
				}
			}
		}
	}

	return rr;
}

int main()
{
	FASTIO();
	PRECISION(8);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y >> points[i].z;

	quickhull(n);
	vector<vector2d> points_projected;
	points_projected.resize(n);

	double vmin = 1e+12;
	for (const auto& pl : planes)
	{
		double dmax = 0;
		vector3df nv = vector3df::cross(points[pl->p3] - points[pl->p1], points[pl->p2] - points[pl->p1]).normalized();
		vector3df uv = vector3df(points[pl->p2] - points[pl->p1]).normalized();
		vector3df vv = vector3df::cross(nv, uv);
		for (int i = 0; i < n; ++i)
		{
			points_projected[i].x = vector3df::dot(points[i], uv);
			points_projected[i].y = vector3df::dot(points[i], vv);
			dmax = max(dmax, abs(vector3df::dot(points[pl->p1] - points[i], nv)));
		}
		vmin = min(vmin, dmax * solution(points_projected) * 3.14159265358979323846);
	}

	cout << vmin;
}