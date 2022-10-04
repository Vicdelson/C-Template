#include<stdio.h>

int main()
{
    long long int i,large,small,total;
    
    do
    {
        
    }
    
    if ( x > y || x > z)
    {
        large = x;
    }
    else if (x < y || x < z)
    {
        small = x;
    }
    else if (y > x || y > z)
    {
        large = y;
    }
    else if (y < x || y < z)
    {
        small = y;
    }
    else if (z > x || z > y)
    {
        large = z;
    }
    else
    {
        small = z;
    }              
    total = large - small;
    printf("%d", total);
    return 0;
}