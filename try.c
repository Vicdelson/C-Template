#include <stdio.h>
#include <math.h>

int main(void)
{
    int d1,d2,d3,d4,d5,d6,hp_player = 100, hp_dragon=100, value, odd, even; 
        scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
        if ((d1+d2+d3)%2==0)
        {
            value = 2;
            even = 1;
        }
        else
        {
            value = 1;
            odd = 2;
        }
    printf("%d", value);
}