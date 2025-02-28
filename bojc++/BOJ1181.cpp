#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string strArray[20000];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> strArray[i];

	sort(strArray, strArray + n, [](const string& a, const string& b) -> bool { return a.length() != b.length() ? a.length() < b.length() : a.compare(b) < 0; });

	cout << strArray[0] << endl;
	for (int i = 1; i < n; i++)
	{
		if (strArray[i].compare(strArray[i - 1]))
			cout << strArray[i] << endl;
	}

	return 0;
}