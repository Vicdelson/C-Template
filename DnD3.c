#include<stdio.h>

#define NUMBER_1 0x38E38E38E38E3800LLU
#define NUMBER_2 0x2AAAAAAAAAAAAAAALLU
#define NUMBER_3 0x1C71C71C71C71C71LLU
#define NUMBER_4 0x7CE66C50E2840000LLU

int main(void)
{
    long long unsigned a,b,c;
    unsigned int dice1,dice2,dice3;
    long long unsigned steps;
    scanf("%d %d %d", &dice1, &dice2, &dice3);
    a = dice1*NUMBER_1;
    b = dice2*NUMBER_2;
    c = dice3*NUMBER_3;
    steps = ((a%NUMBER_4)+(((b%NUMBER_4)+(c%NUMBER_4))%NUMBER_4))%NUMBER_4;
    printf("%llu",steps);
    return 0;
}