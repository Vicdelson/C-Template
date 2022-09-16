#include <stdio.h>

int main(void)
{
    float x = 167, y = 77;
    scanf("%f %f", &x, &y);
    x/=100;
    x*=x;
    float result = (y/x);
    printf("%.6f", result);
    return 0;
}
/*done*/