#include <bits/stdc++.h>

using namespace std;
struct vector2d
{
	double x;
	double y;
};

double dot(vector2d a, vector2d b)
{
	return a.x * b.x + a.y * b.y;
}

double magnitude(vector2d v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

vector2d normalize(vector2d v)
{
	double m = magnitude(v);
	return { v.x / m, v.y / m };
}

int main()
{
	vector2d pointA[4];
	vector2d pointB[4];

	for (int i = 0; i < 4; i++)
		cin >> pointA[i].x >> pointA[i].y;
	for (int i = 0; i < 4; i++)
		cin >> pointB[i].x >> pointB[i].y;

	bool result = true;

	vector2d delta =
	{
		(pointB[0].x + pointB[2].x - pointA[0].x - pointA[2].x) * 0.5,
		(pointB[0].y + pointB[2].y - pointA[0].y - pointA[2].y) * 0.5
	};

	vector2d edge[4] =
	{
		{ pointA[1].x - pointA[0].x, pointA[1].y - pointA[0].y },
		{ pointA[2].x - pointA[1].x, pointA[2].y - pointA[1].y },
		{ pointB[1].x - pointB[0].x, pointB[1].y - pointB[0].y },
		{ pointB[2].x - pointB[1].x, pointB[2].y - pointB[1].y }
	};

	vector<vector2d> unit;
	for (int i = 0; i < sizeof(edge) / sizeof(vector2d); i++)
	{
		if (magnitude(edge[i]) > 0.0)
			unit.push_back(normalize(edge[i]));
		else
		{
			result = false;
			break;
		}
	}

	for (int i = 0; i < unit.size() && result; i++)
	{
		vector2d u = unit[i];
		if (abs(dot(delta, u)) * 2.0 >= abs(dot(edge[0], u)) + abs(dot(edge[1], u)) + abs(dot(edge[2], u)) + abs(dot(edge[3], u)))
			result = false;
	}

	cout << (int)result << endl;
	return 0;
}