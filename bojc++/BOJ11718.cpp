#include <stdio.h>

int main()
{
	char buffer[128];
	while (gets(buffer))
		puts(buffer);
	return 0;
}