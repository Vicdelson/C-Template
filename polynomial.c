#include <math.h>
#include <stdio.h>

int main(void)
{
    float x = 5.5, a = 4, b = 3, c = 2;
    scanf("%f", &x);
    float result = 7*pow(x,a)-8*pow(x,b)-pow(x,c)+6*x-22;
    printf("%.1f\n", result);
    return 0;
}