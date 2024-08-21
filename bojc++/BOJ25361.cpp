#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

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
using vector3df = vector3d<double>;
using query = tuple<int64, int, int, double>;

struct segment
{
	int node0;
	int node1;
	double m;
	double h;
};

struct segment_alt
{
	int node0;
	int node1;
	double s;
};

struct component
{
	double z = 1e+10;
	double s;
	double m;
	double h;

	void validate(double z0)
	{
		s += integral(z0, z);
		z = z0;
	}

	double integral(double z0, double z1) const
	{
		double dz1 = z1 - z0;
		double dz2 = z1 * z1 - z0 * z0;
		return m / 2 * dz2 + h * dz1;
	}
};

vector3di vertices[100000];
component components[100000];
query queries[100000];
int nodes[100000];

vector<segment> segments;
vector<segment_alt> segments_alt;
vector<tuple<double, void(*)(double, size_t), size_t>> events;

inline int find_node(int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes[node]));
}

inline void union_node(int node0, int node1)
{
	nodes[node1] = node0;
	
	component& lhs = components[node0];
	component& rhs = components[node1];

	double z = min(lhs.z, rhs.z);
	lhs.validate(z);
	rhs.validate(z);

	lhs.s += rhs.s;
	lhs.m += rhs.m;
	lhs.h += rhs.h;
}

void add_segment(double z, size_t index)
{
	segment& ref = segments[index];

	int up = find_node(ref.node1);

	components[up].validate(z);
	components[up].h += ref.h;
	components[up].m += ref.m;
}

void remove_segment(double z, size_t index)
{
	segment& ref = segments[index];

	int up = find_node(ref.node0);
	int vp = find_node(ref.node1);
	if (up != vp)
		union_node(up, vp);

	components[up].validate(z);
	components[up].h -= ref.h;
	components[up].m -= ref.m;
}

void add_segment_alt(double z, size_t index)
{
	segment_alt& ref = segments_alt[index];

	int up = find_node(ref.node0);
	int vp = find_node(ref.node1);
	if (up != vp)
		union_node(up, vp);

	components[up].validate(z);
	components[up].s += ref.s;
}

int main()
{
    FASTIO();
    PRECISION(15);

    int n, m, q;
    cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> vertices[i].x >> vertices[i].y >> vertices[i].z;
    cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vector3df va = vertices[a - 1];
		vector3df vb = vertices[b - 1];
		vector3df vc = vertices[c - 1];

		if (va.z > vb.z)
		{
			swap(va, vb);
			swap(a, b);
		}
		if (vb.z > vc.z)
		{
			swap(vb, vc);
			swap(b, c);
		}
		if (va.z > vb.z)
		{
			swap(va, vb);
			swap(a, b);
		}

		vector3df vp = vector3df::cross(vb - va, vc - va);
		if (va.z == vc.z)
		{
			double s = vp.magnitude();

			segment_alt lab;
			lab.node0 = a - 1;
			lab.node1 = b - 1;
			lab.s = s / 4;

			segment_alt lbc;
			lbc.node0 = b - 1;
			lbc.node1 = c - 1;
			lbc.s = s / 4;

			events.emplace_back(va.z, add_segment_alt, segments_alt.size());
			segments_alt.emplace_back(lab);
			events.emplace_back(va.z, add_segment_alt, segments_alt.size());
			segments_alt.emplace_back(lbc);

			continue;
		}

		double sint = vector3df::cross(vp.normalized(), vector3df(0.0f, 0.0f, 1.0f)).magnitude();
		double t = (vb.z - vc.z) / (va.z - vc.z);
		vector3df vbp = va * t + vc * (1 - t);
		double lb = (vbp - vb).magnitude();

		if (va.z == vb.z)
		{
			segment_alt lab;
			lab.node0 = a - 1;
			lab.node1 = b - 1;
			lab.s = 0;
			events.emplace_back(va.z, add_segment_alt, segments_alt.size());
			segments_alt.emplace_back(lab);
		}
		else
		{
			segment lab;
			lab.node0 = a - 1;
			lab.node1 = b - 1;
			lab.m = lb / (vb.z - va.z) / sint;
			lab.h = -lab.m * va.z;
			events.emplace_back(va.z, remove_segment, segments.size());
			events.emplace_back(vb.z, add_segment, segments.size());
			segments.emplace_back(lab);
		}

		if (vb.z == vc.z)
		{
			segment_alt lbc;
			lbc.node0 = b - 1;
			lbc.node1 = c - 1;
			lbc.s = 0;
			events.emplace_back(vb.z, add_segment_alt, segments_alt.size());
			segments_alt.emplace_back(lbc);
		}
		else
		{
			segment lbc;
			lbc.node0 = b - 1;
			lbc.node1 = c - 1;
			lbc.m = -lb / (vc.z - vb.z) / sint;
			lbc.h = -lbc.m * vc.z;
			events.emplace_back(vb.z, remove_segment, segments.size());
			events.emplace_back(vc.z, add_segment, segments.size());
			segments.emplace_back(lbc);
		}
	}

    cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int64 h;
		int p;
		cin >> h >> p;
		queries[i] = make_tuple(h, p - 1, i, -1);
	}

	sort(queries, queries + q, greater<query>());
	sort(events.begin(), events.end(), [](const auto& lhs, const auto& rhs) { return get<0>(lhs) > get<0>(rhs); });
	memset(nodes, -1, sizeof(nodes));

	int j = 0;
	for (auto& [h, p, i, r] : queries)
	{
		if (vertices[p].z <= h)
			continue;
		while (j < events.size() && get<0>(events[j]) > h)
		{
			get<1>(events[j])(get<0>(events[j]), get<2>(events[j]));
			++j;
		}
		component& ref = components[find_node(p)];
		ref.validate(h);
		r = ref.s;
	}

	sort(queries, queries + q, [](const auto& lhs, const auto& rhs) { return get<2>(lhs) < get<2>(rhs); });
	for (int i = 0; i < q; ++i)
		cout << get<3>(queries[i]) << '\n';
}