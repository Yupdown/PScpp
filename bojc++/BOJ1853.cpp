#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct vector2d
{
	int x;
	int y;
};

bool vector2d_greater_y(const vector2d& va, const vector2d& vb)
{
	return va.y < vb.y;
}

void divide_convexhull(vector2d* convexhull, int size, vector<vector2d>* out_top, vector<vector2d>* out_bottom)
{
	for (int i = 0; i < size; ++i)
	{
		vector2d v0 = convexhull[i];
		vector2d v1 = convexhull[(i + 1) % size];
		vector2d v2 = convexhull[(i + 2) % size];

		if (v0.y > v1.y || v1.y > v2.y)
			out_top->push_back(v1);
		if (v0.y < v1.y || v1.y < v2.y)
			out_bottom->push_back(v1);
	}

	sort(out_top->begin(), out_top->end(), vector2d_greater_y);
	sort(out_bottom->begin(), out_bottom->end(), vector2d_greater_y);
}

double lerp(double a, double b, double t)
{
	return a + (b - a) * t;
}

pair<int, int> create_width_map(vector2d* points, int size, double* dest)
{
	vector<vector2d> top, bot;
	divide_convexhull(points, size, &top, &bot);

	for (int i = 0; i < top.size() - 1; ++i)
	{
		int a = top[i].y;
		int b = top[i + 1].y;

		for (int j = a; j < (i < top.size() - 2 ? b : b + 1); ++j)
			dest[j + 512] = lerp(top[i].x, top[i + 1].x, (double)(j - a) / (b - a));
	}

	for (int i = 0; i < bot.size() - 1; ++i)
	{
		int a = bot[i].y;
		int b = bot[i + 1].y;

		for (int j = a; j < (i < bot.size() - 2 ? b : b + 1); ++j)
			dest[j + 512] -= lerp(bot[i].x, bot[i + 1].x, (double)(j - a) / (b - a));
	}

	return { top.front().y + 512, top.back().y + 512 };
}

double get_integral(double m0, double m1, double b0, double b1)
{
	return m0 * m1 / 3.0 + (m0 * b1 + m1 * b0) / 2.0 + b0 * b1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int nxz, nyz;
	vector2d xz[1000], yz[1000];
	double wxz[1024], wyz[1024];

	cout << fixed;
	cout.precision(2);

	cin >> nxz;
	for (int i = 0; i < nxz; ++i)
		cin >> xz[i].x >> xz[i].y;

	cin >> nyz;
	for (int i = 0; i < nyz; ++i)
		cin >> yz[i].x >> yz[i].y;

	create_width_map(xz, nxz, wxz);
	pair<int, int> range = create_width_map(yz, nyz, wyz);

	double result = 0.0;
	for (int z = range.first; z < range.second; ++z)
		result += get_integral(wxz[z + 1] - wxz[z], wyz[z + 1] - wyz[z], wxz[z], wyz[z]);

	cout << result << endl;
	return 0;
}