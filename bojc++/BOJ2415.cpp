#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

struct vector2d
{
	int64 x;
	int64 y;
};

struct diagonal
{
	vector2d p1;
	vector2d p2;
	int64 dist;
};

int64 size_rectangle(const diagonal& a, const diagonal& b)
{
	int64 xmin = min(min(a.p1.x, a.p2.x), min(b.p1.x, b.p2.x));
	int64 xmax = max(max(a.p1.x, a.p2.x), max(b.p1.x, b.p2.x));
	int64 ymin = min(min(a.p1.y, a.p2.y), min(b.p1.y, b.p2.y));
	int64 ymax = max(max(a.p1.y, a.p2.y), max(b.p1.y, b.p2.y));

	vector2d p1 = a.p1;
	vector2d p2 = b.p1;
	vector2d p3 = b.p2;

	int64 s1 = (xmax - xmin) * (ymax - ymin);
	int64 s2 = abs((p2.x - p1.x) * (p2.y - p1.y));
	int64 s3 = abs((p3.x - p1.x) * (p3.y - p1.y));

	return s1 - s2 - s3;
}

int64 clear_map(map<int64, vector<diagonal>*>* m)
{
	int64 sizeMax = 0;

	for (auto var : *m)
	{
		vector<diagonal>* c = var.second;
		if (c->size() > 1)
		{
			for (auto i = c->begin(); i != c->end(); ++i)
			{
				for (auto j = i + 1; j != c->end(); ++j)
					sizeMax = max(sizeMax, size_rectangle(*i, *j));
			}
		}
		delete c;
	}

	return sizeMax;
}

vector2d point[1500];
vector<diagonal> container;

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> point[i].x >> point[i].y;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			vector2d p1 = point[i];
			vector2d p2 = point[j];

			int64 dx = p1.x - p2.x;
			int64 dy = p1.y - p2.y;
			int64 dist = dx * dx + dy * dy;

			container.push_back({ p1, p2, dist });
		}
	}

	sort(container.begin(), container.end(), [](const diagonal& a, const diagonal& b) -> bool { return a.dist > b.dist; });

	int64 sizeMax = 0;
	int64 distMax = 0;
	int64 lastDist = 0;

	map<int64, vector<diagonal>*> m;
	for (auto iter = container.begin(); iter != container.end(); ++iter)
	{
		if (lastDist != iter->dist)
		{
			sizeMax = max(sizeMax, clear_map(&m));
			m.clear();
			lastDist = iter->dist;
		}

		vector2d p1 = iter->p1;
		vector2d p2 = iter->p2;

		int64 cent = p1.x + p2.x + (p1.y + p2.y) * 200000001;

		auto pair = m.find(cent);
		vector<diagonal>* v_diagonal;

		if (pair != m.end())
			v_diagonal = pair->second;
		else
		{
			v_diagonal = new vector<diagonal>();
			m.insert(make_pair(cent, v_diagonal));
		}
		v_diagonal->push_back(*iter);
	}

	sizeMax = max(sizeMax, clear_map(&m));

	cout << sizeMax << endl;
	return 0;
}