#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

constexpr double EPS = 1e-9;
constexpr double INF = 1e+9;

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

// p: pivot position
// vz: normal vector (outward, normalized)
// vx, vy: tangent vector (normalized)
struct plane
{
	vector3df p, vx, vy, vz;
};

plane planes[25];

vector<vector<pair<int, double>>> graph;
vector<vector<pair<int, vector3df>>> points;

// get an arc length of euclidean distance of two points (assuming the both points are on the surface of the sphere)
inline double get_arclen(double dist)
{
	return 12740 * asin(dist / 12740);
}

void generate_graph(int n, int r)
{
	double rp = 6370 * sin(static_cast<double>(r) / 6370);

	graph.clear();
	points.clear();
	graph.resize(n);
	points.resize(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			vector3df rv = vector3df::cross(planes[i].vz, planes[j].vz);
			// if the both planes are exactly opposite
			if (rv.sqr_magnitude() <= EPS)
				continue;
			rv = rv.normalized();
			vector3df uv = vector3df::cross(rv, planes[j].vz);
			double d = vector3df::dot(planes[j].p - planes[i].p, planes[i].vz);
			vector3df pp = (planes[j].p - planes[i].p) + uv * d / -vector3df::dot(planes[i].vz, uv);
			vector3df ppproj = vector3df(vector3df::dot(planes[i].vx, pp), vector3df::dot(planes[i].vy, pp), vector3df::dot(planes[i].vz, pp));
			vector3df nvproj = vector3df(vector3df::dot(planes[i].vx, planes[j].vz), vector3df::dot(planes[i].vy, planes[j].vz), 0).normalized();
			double dist = vector3df::dot(ppproj, nvproj);
			if (dist > rp)
				continue;
			else if (dist >= -rp)
			{
				graph.emplace_back();
				graph.emplace_back();
				int k = graph.size() - 2;
				int l = graph.size() - 1;

				graph[i].emplace_back(k, r);
				graph[k].emplace_back(i, r);
				graph[i].emplace_back(l, r);
				graph[l].emplace_back(i, r);
				graph[j].emplace_back(k, r);
				graph[k].emplace_back(j, r);
				graph[j].emplace_back(l, r);
				graph[l].emplace_back(j, r);

				double dp = sqrt(rp * rp - dist * dist);
				graph[k].emplace_back(l, get_arclen(dp * 2));
				graph[l].emplace_back(k, get_arclen(dp * 2));

				vector3df pa = nvproj * dist + vector3df(-nvproj.y, nvproj.x, 0) * dp;
				vector3df pb = nvproj * dist + vector3df(nvproj.y, -nvproj.x, 0) * dp;

				for (const auto& [m, p] : points[i])
				{
					graph[k].emplace_back(m, get_arclen((pa - p).magnitude()));
					graph[l].emplace_back(m, get_arclen((pb - p).magnitude()));
					graph[m].emplace_back(k, get_arclen((pa - p).magnitude()));
					graph[m].emplace_back(l, get_arclen((pb - p).magnitude()));
				}
				points[i].emplace_back(k, pa);
				points[i].emplace_back(l, pb);

				pa = (planes[i].vx * pa.x + planes[i].vy * pa.y) + planes[i].p - planes[j].p;
				pb = (planes[i].vx * pb.x + planes[i].vy * pb.y) + planes[i].p - planes[j].p;
				pa = vector3df(vector3df::dot(planes[j].vx, pa), vector3df::dot(planes[j].vy, pa), 0);
				pb = vector3df(vector3df::dot(planes[j].vx, pb), vector3df::dot(planes[j].vy, pb), 0);

				for (const auto& [m, p] : points[j])
				{
					graph[k].emplace_back(m, get_arclen((pa - p).magnitude()));
					graph[l].emplace_back(m, get_arclen((pb - p).magnitude()));
					graph[m].emplace_back(k, get_arclen((pa - p).magnitude()));
					graph[m].emplace_back(l, get_arclen((pb - p).magnitude()));
				}
				points[j].emplace_back(k, pa);
				points[j].emplace_back(l, pb);
			}

			double delta = get_arclen((planes[i].vz - planes[j].vz).magnitude() * 6370);
			graph[i].emplace_back(j, delta);
			graph[j].emplace_back(i, delta);
		}
	}
}

double solution(int n, int s, int t, int c)
{
	// floyd warshall table
	double table[25][25];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			table[i][j] = INF;

		priority_queue<pair<double, int>> pq;
		vector<double> memo;
		memo.resize(graph.size(), INF);
		memo[i] = 0;
		pq.emplace(0, i);

		while (!pq.empty())
		{
			auto [dist, node] = pq.top();
			pq.pop();
			dist = -dist;
			if (dist > memo[node])
				continue;
			if (node < n)
				table[i][node] = dist;
			for (const auto& [node_next, delta] : graph[node])
			{
				double dist_next = memo[node] + delta;
				if (dist_next > c)
					continue;
				if (dist_next >= memo[node_next])
					continue;
				memo[node_next] = dist_next;
				pq.emplace(-dist_next, node_next);
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
				table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
		}
	}

	return table[s][t];
}

int main()
{
	ofstream cout{ "out.txt" };

	FASTIO();
	PRECISION(3);

	int n, r, m = 0;
	while (cin >> n >> r)
	{
		for (int i = 0; i < n; ++i)
		{
			double lon, lat;
			cin >> lon >> lat;
			lon *= M_PI / 180;
			lat *= M_PI / 180;
			// Generates the plane's own coordination system
			vector3df vn = vector3df(cos(lon) * cos(lat), sin(lon) * cos(lat), sin(lat));
			planes[i].p = vn * 6370 * cos(static_cast<double>(r) / 6370);
			planes[i].vz = vn;
			planes[i].vy = vector3df(cos(lon) * -sin(lat), sin(lon) * -sin(lat), cos(lat));
			planes[i].vx = vector3df::cross(planes[i].vy, planes[i].vz);
		}

		generate_graph(n, r);

		int q;
		cin >> q;
		cout << "Case " << ++m << ":\n";
		for (int i = 0; i < q; ++i)
		{
			int s, t, c;
			cin >> s >> t >> c;
			double v = solution(n, s - 1, t - 1, c);
			if (v >= INF)
				cout << "impossible\n";
			else
				cout << v << "\n";
		}
	}
}