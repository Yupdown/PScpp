#include <iostream>

int main()
{
	int i;
	char s[1024];
	std::cin >> s >> i;
	std::cout << s[i - 1];
}