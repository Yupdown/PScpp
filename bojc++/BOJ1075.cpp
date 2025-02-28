#include <iostream>

using namespace std;

int main()
{
    int n, f, i = 0;
    scanf("%d %d", &n, &f);
    while ((n / 100 * 100 + i) % f != 0)
        ++i;
    printf("%02d\n", i);
    return 0;
}