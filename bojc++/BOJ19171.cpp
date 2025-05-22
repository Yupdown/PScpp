#include <bits/stdc++.h>
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

template <typename T>
struct vector3d
{
    T x, y, z;
    vector3d() : vector3d(0, 0, 0) {}
    vector3d(T x, T y, T z) : x(x), y(y), z(z) {}

    T sqr_magnitude() const { return dot(*this, *this); }
    double magnitude() const { return sqrt(sqr_magnitude()); }
    vector3d normalized() const { return *this / magnitude(); }
    vector3d operator-() const { return { -x, -y, -z }; };
    vector3d operator+(const vector3d& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z }; };
    vector3d operator-(const vector3d& rhs) const { return *this + (-rhs); };
    vector3d operator*(const T& rhs) const { return { x * rhs, y * rhs, z * rhs }; };
    vector3d operator/(const T& rhs) const { return { x / rhs, y / rhs, z / rhs }; };
    bool operator==(const vector3d& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; };
    bool operator!=(const vector3d& rhs) const { return !(*this == rhs); };

    static T dot(const vector3d& lhs, const vector3d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }
    static vector3d cross(const vector3d& lhs, const vector3d& rhs) { return { lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x }; }
};

using int64 = long long;
using vector3di = vector3d<int64>;
using vector3df = vector3d<double>;

vector3df p1, p2, p3;

double get_value(const vector3df& p)
{
    return (p - p1).magnitude() + (p - p2).magnitude() + (p - p3).magnitude();
}

vector3df get_gradient(const vector3df& p)
{
    return vector3df(
        (p.x - p1.x) / (p - p1).magnitude() + (p.x - p2.x) / (p - p2).magnitude() + (p.x - p3.x) / (p - p3).magnitude(),
        (p.y - p1.y) / (p - p1).magnitude() + (p.y - p2.y) / (p - p2).magnitude() + (p.y - p3.y) / (p - p3).magnitude(),
        0);
}

int main()
{
	PRECISION(6);

    cin >> p1.x >> p1.y >> p1.z;
    cin >> p2.x >> p2.y >> p2.z;
    cin >> p3.x >> p3.y >> p3.z;

    vector3df zBasis = vector3df::cross(p2 - p1, p3 - p1);
    if (zBasis.sqr_magnitude() == 0)
    {
        double vMin = get_value(p1);
        vMin = min(vMin, get_value(p2));
        vMin = min(vMin, get_value(p3));
        cout << vMin;
    }
    else
    {
        zBasis = zBasis.normalized();
        vector3df yBasis = (p2 - p1).normalized();
        vector3df xBasis = vector3df::cross(yBasis, zBasis);

        vector3df p2t = p2 - p1;
        vector3df p3t = p3 - p1;
        p1 = vector3df(0, 0, 0);
        p2.x = vector3df::dot(p2t, xBasis);
        p2.y = vector3df::dot(p2t, yBasis);
        p2.z = vector3df::dot(p2t, zBasis);
        p3.x = vector3df::dot(p3t, xBasis);
        p3.y = vector3df::dot(p3t, yBasis);
        p3.z = vector3df::dot(p3t, zBasis);

        vector3df pv = (p1 + p2 + p3) / 3;
        for (int n = 10'000'000; n > 0; --n)
        {
            vector3df gv = get_gradient(pv);
            pv = pv - gv * n / 10'000;
        }
        cout << get_value(pv);
    }
}