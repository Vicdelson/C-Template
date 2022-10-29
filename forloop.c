#include <stdio.h>

int main()
{
    float value = 0;
    for(int i =0;i<100;i++)
    {
        value+=0.03;
    }
    printf("%f\n", value);
}