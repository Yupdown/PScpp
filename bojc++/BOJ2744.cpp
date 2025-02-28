#include <stdio.h>
int main()
{
    char c;
    while ((c = getchar()) != '\n')
        putchar(c < 'a' ? c + 32 : c - 32);
    return 0;
}