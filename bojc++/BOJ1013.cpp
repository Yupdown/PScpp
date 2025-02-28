#include <iostream>
#include <regex>

using namespace std;

int main()
{
	int t;
	char input[256];
	regex pattern = regex("(100+1+|01)+");

	cin >> t;
	while (t-- > 0)
	{
		cin >> input;
		cout << (regex_match(input, pattern) ? "YES" : "NO") << endl;
	}

	return 0;
}