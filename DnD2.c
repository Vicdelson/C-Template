#include <stdio.h>

int main(void)
{
    int d1,d2,d3,d4,d5,d6,player = 100, dragon=100, value;
    while(player > 0 && dragon > 0)
    {  
        scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
        if ((d1+d2+d3)%2==0)
        {   
             if((d5-d4)>d6||(d4-d5)>d6)
            {
                player -= 15;
            }
            else if((d4+d5)!=d6)
            {
                player -= 5;
            }
            else
            {
                player -= 0;
            }
        }
        else
        {
            if(d6>d5&&d5>d4)
            {
                dragon -= 25;
            }
            else if(d4%2==d5%2||d5%2==d6%2)
            {
                dragon -= 5;
            }
            else
            {
                dragon -= 0;
            }
        }
    }
    if(player <= 0)
    {
        printf("Dragon wins");
    }
    else
        printf("Player wins");
return 0;
}