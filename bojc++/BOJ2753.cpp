#include<stdio.h>
int main() { int a; scanf("%d", &a); printf("%d", !(a % 4) && (a % 100 || !(a % 400))); return 0; }