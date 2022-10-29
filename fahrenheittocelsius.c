#include <stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0/9.0f)

int main(void)
{
    float fahrenheit, celsius;
    printf("Enter Fahrenheit temperature :");
    scanf("%f", &fahrenheit);
    fahrenheit = (fahrenheit - FREEZING_PT)*SCALE_FACTOR;
    printf("Celsius equivalnt : %.1f\n", fahrenheit);
}