#include <stdio.h>

int main()
{
    int n, m, min = 0, max = 0;
    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &m);
        min = m > min && min > 0 ? min : m;
        max = m < max && max > 0 ? max : m;
    }
    printf("%d\n", min * max);
    return 0;
}