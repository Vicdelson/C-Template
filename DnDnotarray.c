#include <stdio.h>

int main(void)
{
    unsigned int dice1,dice2,dice3,dice4;
    //step 1
    unsigned short value;
    unsigned int N;
    unsigned int d1,d2,d3,d4;
    unsigned int temp= 0x00000000;

    scanf("%u%d%d%d%d", &N,&dice1, &dice2,&dice3,&dice4);
    d1=dice1;
    d2=dice2;
    d3=dice3;
    d4=dice4;

    d1 = N>>(4-dice1)*8&255;
    d2 = N>>(4-dice2)*8&255;
    d3 = N>>(4-dice3)*8&255;
    d4 = N>>(4-dice4)*8&255;
    //step 2
    temp |= (d1^d2) << 24;
    //step 3
    temp |= (d2&d3) << 16;
    //step 4
    temp |= (d1|d3) <<8;
    //step 5
    temp |=~ d4&255;
    //step 6
    temp= temp<<(32-dice1-dice2-dice3-dice4) | temp>>(dice1+dice2+dice3+dice4);
    //temp = temp>>(d1+d2+d3+d4)|temp<<(32-(d1+d2+d3+d4));
    //step 7
    value = temp >> 16^temp&0xffff;
    printf("%hu", value);
    return 0;
}