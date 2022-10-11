#include<stdio.h>

int main(void)
{
    const int scores[3];
    for(int i = 0;i < 3; i++)
    {
        scanf("%d",&scores[i]);
        scores[i] = scores;
    }
    /*scores[0]= 77;
    scores[1]= 77;
    scores[2]= 78;*/

    printf("%f", ((scores[0]+scores[1]+scores[2])/(float)3));
}