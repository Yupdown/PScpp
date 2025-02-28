#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n + i; ++j)
            printf("%c", j < n - i - 1 ? ' ' : '*');
        printf("\n");
    }
    return 0;
}