#include <iostream>
#include <math.h>

using namespace std;

const int SIZEOF_CACHE = 16;
const int SIZEOF_BITMASK = 1 << SIZEOF_CACHE;

int function(int w[SIZEOF_CACHE][SIZEOF_CACHE], int cache[SIZEOF_CACHE][SIZEOF_BITMASK], int n, int node, int visited)
{
	if (visited == (1 << n) - 1)
		return w[node][0] != 0 ? w[node][0] : -1;

	if (cache[node][visited] == -2)
		return -1;
	if (cache[node][visited] != -1)
		return cache[node][visited];

	for (int i = 0; i < n; i++)
	{
		if ((visited & (1 << i)) != 0 || w[node][i] == 0)
			continue;
		int value = function(w, cache, n, i, visited | (1 << i));
		if (value < 0)
			continue;
		value += w[node][i];
		cache[node][visited] = cache[node][visited] < 0 ? value : min(cache[node][visited], value);
	}

	if (cache[node][visited] < 0)
		cache[node][visited] = -2;
	return cache[node][visited];
}

int main()
{
	int n;
	cin >> n;

	int w[SIZEOF_CACHE][SIZEOF_CACHE];

	for (int i = 0; i < n * n; i++)
		cin >> w[i / n][i % n];

	int cache[SIZEOF_CACHE][SIZEOF_BITMASK];
	for (int i = 0; i < SIZEOF_CACHE * SIZEOF_BITMASK; i++)
		cache[i / SIZEOF_BITMASK][i % SIZEOF_BITMASK] = -1;

	cout << function(w, cache, n, 0, 1) << endl;

	return 0;
}