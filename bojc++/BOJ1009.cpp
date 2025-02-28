#include <stdio.h>

int main()
{
    int t;
    int* a, * b;

    scanf("%d", &t);

    a = new int[t];
    b = new int[t];

    for (int i = 0; i < t; i++)
        scanf("%d %d", &a[i], &b[i]);

    for (int i = 0; i < t; i++)
    {
        int temp = a[i] % 10;
        while (--b[i] > 0)
            temp = temp * a[i] % 10;
        printf("%d\n", temp == 0 ? 10 : temp);
    }

    delete[] a;
    delete[] b;

    return 0;
}