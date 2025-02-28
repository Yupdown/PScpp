#include <iostream>
#include <stack>

using namespace std;

bool getResult(char* string)
{
	stack<char> bracket;

	for (int i = 0; string[i] != 0; i++)
	{
		switch (string[i])
		{
		case '(':
			bracket.push(')');
			break;
		case '[':
			bracket.push(']');
			break;

		case ')':
		case ']':
			if (!(bracket.size() > 0))
				return false;
			if (string[i] != bracket.top())
				return false;
			bracket.pop();
			break;

		default:
			break;
		}
	}

	return !(bracket.size() > 0);
}

int main()
{
	char string[128];

	cin.getline(string, 128);
	while (string[0] != '.')
	{
		cout << (getResult(string) ? "yes" : "no") << endl;
		cin.getline(string, 128);
	}
}