#include <stdio.h>

int main()
{
    int r = 0;
    char str[16], * p;

    scanf("%s", str);
    for (p = str; *p != 0; p++)
        r += ((*p > 'R' ? (*p > 'Y' ? *p - 2 : *p - 1) : *p) - 'A') / 3 + 3;
    printf("%d\n", r);
    return 0;
}