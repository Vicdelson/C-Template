#include <stdio.h>
#include <math.h>

int main(void)
{
    float x = 167, y = 77, z = 2;
    scanf("%f", &x);
    scanf("%f", &y);
    float result = x/ pow(y,z);
    printf("%f\n", result);
    return 0;
}