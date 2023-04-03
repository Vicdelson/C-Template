#include <stdio.h>

int main()
{
    int x,position,i=0,max = 0;
    while(x!=-1)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        i++;
        if(x>max)
        {
            max=x;
            position=i;
        }
    }
    printf("\nThe maximum enter value is %d",max);
    printf("\nThis was entered at position %d",position);
}