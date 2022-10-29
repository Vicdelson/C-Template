#include <stdio.h>

int main(void)
{
    int dice1,dice2,dice3,dice4;
    //step 1
    unsigned value = 0;
    unsigned int N;
    unsigned int byte[4];
    unsigned int temp= 0x00000000;

    scanf("%u%d%d%d%d", &N,&dice1, &dice2,&dice3,&dice4);

    byte[dice1-1] = N>>(4-dice1)*8&255;
    byte[dice2-1] = N>>(4-dice2)*8&255;
    byte[dice3-1] = N>>(4-dice3)*8&255;
    byte[dice4-1] = N>>(4-dice4)*8&255;
    //step 2
    temp |= byte[dice1-1]^byte[dice2-1] << 24;
    //step 3
    temp |= byte[dice2-1]&byte[dice3-1] << 16;
    //step 4
    temp |= byte[dice1-1]|byte[dice3-1]<<8;
    //step 5
    temp |=~ byte[dice4-1]&255;
    //step 6
    temp = temp>>(dice1+dice2+dice3+dice4)|temp<<(32-(dice1+dice2+dice3+dice4));
    //step 7
    unsigned upper = temp>>16;
    unsigned lower = temp&0xffff;
    value = upper ^ lower;
    printf("%u", value);
    return 0;
}