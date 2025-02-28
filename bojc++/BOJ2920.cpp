#include <iostream>

using namespace std;

int main()
{
	bool ascending = true, descending = true;

	for (int i = 0, last = 0; i < 8; i++)
	{
		int n;
		cin >> n;

		if (i > 0)
		{
			if (n != last + 1)
				ascending = false;
			if (n != last - 1)
				descending = false;
		}

		last = n;
	}

	cout << (ascending ? "ascending" : (descending ? "descending" : "mixed")) << endl;

	return 0;
}