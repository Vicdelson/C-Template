#include <stdio.h>

int power(int x, int n)
{
    if (n == 0)
    return 1;
    else
    return x * power(x, n - 1);
}

int main()
{
    int n;
    int x;
    printf("Input number :");
    scanf("%d",&x);
    printf("Power of :");
    scanf("%d",&n);
    printf("%d", power(x,n));
}