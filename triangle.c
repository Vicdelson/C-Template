#include <stdio.h>

int main(void)
{
    int i, j, angle, layers, space;
    scanf("%d %d", &angle, &layers);
    if(angle == 1)
    {
        for(i=layers;i>0;--i)
        {
            for(j=0;j<i;++j)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    else if(angle == 2)
    {
        for(i = 1;i<=layers;++i)
        {
            for(j = 1; j <= i; ++j)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    else if(angle == 3)
    {
        for(i= layers;i>0;--i)
        {
            for(space = 0; space < layers - i;space++)
            {
                printf(" ");
            }
            for(j=i;j<=2*i-1;++j)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    else if(angle == 4)
    {
        for(i = 1; i <= layers; ++i)
        {
            for(space = 1; space <= layers-i;space++)
            {
                printf(" ");
            }
            for(j=0;j!= i;++j)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    return 0;
}