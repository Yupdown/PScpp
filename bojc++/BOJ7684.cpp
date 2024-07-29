#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

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

vector3di points[25];

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
plane* edges[25][25];

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

int main()
{
	FASTIO();

	int n;
	while (cin >> n && n > 0)
	{
		for (int i = 0; i < n; ++i)
			cin >> points[i].x >> points[i].y >> points[i].z;

		planes.clear();
		memset(edges, 0, sizeof(edges));
		quickhull(n);

		double ret = 0;
		for (const auto& pl : planes)
			ret += vector3di::cross(points[pl->p2] - points[pl->p1], points[pl->p3] - points[pl->p1]).magnitude();
		cout << static_cast<int64>(round(ret * 0.5)) << '\n';
	}
}