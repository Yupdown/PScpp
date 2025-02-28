#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Building
{
public:
	int duration;
	int value;
	int indegree;
	vector<Building*> nextBuildings;

	Building(int duration)
	{
		this->duration = duration;
		this->value = duration;
		this->indegree = 0;
	}
};

int getResult(Building** buildings, int size, Building* destination)
{
	queue<Building*> q;

	for (int i = 0; i < size; i++)
	{
		if (buildings[i]->indegree == 0)
			q.push(buildings[i]);
	}

	Building* current;

	do
	{
		current = q.front();

		for (int i = 0; i < current->nextBuildings.size(); i++)
		{
			Building* next = current->nextBuildings[i];
			next->value = max(next->value, current->value + next->duration);
			if (--(next->indegree) == 0)
				q.push(next);
		}
		q.pop();
	} while (current != destination);

	return current->value;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;

		Building** buildings = new Building * [n];

		for (int i = 0; i < n; i++)
		{
			int d;
			cin >> d;

			buildings[i] = new Building(d);
		}

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;

			buildings[x - 1]->nextBuildings.push_back(buildings[y - 1]);
			buildings[y - 1]->indegree++;
		}

		int w;
		cin >> w;

		cout << getResult(buildings, n, buildings[w - 1]) << endl;
	}
}