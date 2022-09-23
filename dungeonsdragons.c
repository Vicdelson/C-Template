#include <math.h>
#include <stdio.h>

int main(void)
{
    int d1,d2,d3,d4,d5,d6,
    first_sum, second_sum;
    scanf("%d %d %d %d %d %d", 
    &d1, &d2, &d3, &d4, &d5, &d6);
    first_sum = d1+d2+d3;
    second_sum = d4+d5;

    if (first_sum <= 10)
    {
        printf("Player attacks: ");
        
        if ()
    }   
    else 
    {
        printf("Dragon attacks: ");
    }
    else if(first_sum <= 10, second_sum < d6)
    {
        printf("Player attacks: Miss");
    }
    else if (first_sum > 10, second_sum != d6 )
    {
        printf("Dragon attacks: Normal Attack");
    }
    else if (first_sum > 10, second_sum = d6)
    {
        printf("Dragon attacks: Critical Hit");
    }
    else if (first_sum >10, d4 == d5)
    {
        printf("Dragon attacks: Miss");
    }
    else if (first_sum >10, d5 == d6)
    {
        printf("Dragon attacks: Miss");
    }
    else if (first_sum >10, d4 == d6)
    {
        printf("Dragon attacks: Miss");
    }
    return 0;
}