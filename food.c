#include<stdio.h>
#include<math.h>
int main()
{   
    unsigned value, small = 2147483647, large = 1, sum;
    while(value != -1)
    {
        {
        scanf("%d",&value);
        if (value == -1)
        {
            break;
        }
    }
    if (value > large)
    {
        large = value;
    }
    if (value < small)
    {
        small = value;
    }
    }
    sum = large - small;
    printf("%d", sum);
    return 0;
}