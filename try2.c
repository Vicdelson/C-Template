#include<stdio.h>
#include<math.h>

int main (void) 
{
    float a = 3, A = sqrt(3);
    scanf("%f", &a);
    A/=4;
    float result = (A*a*a);
    printf("%.3f", result);
    return 0;
}
