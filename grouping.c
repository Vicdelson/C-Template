#include <math.h>
#include <stdio.h>

int main(void)
{
    int i, j, a, b;
    scanf("%d %d", &i, &j);
    a = i / j;
    b = i % j;
    printf("%d %d", a, b);
    return 0;
}