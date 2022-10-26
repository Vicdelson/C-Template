#include <stdio.h>

int main () {
    unsigned N,temp=0x00000000,d1,d2,d3,d4,D1,D2,D3,D4;
    unsigned short K;
    scanf("%u%d%d%d%d",&N,&d1,&d2,&d3,&d4);
    D1=d1,D2=d2,D3=d3,D4=d4;
    D1=N>>(4-d1)*8 & 255,D2=N>>(4-d2)*8 & 255,D3=N>>(4-d3)*8 & 255,D4=N>>(4-d4)*8 & 255;
    temp |=(D1 ^ D2) << 24;
    temp |=(D3 & D2) << 16;
    temp |=(D3 | D1) << 8;
    temp |=~D4 & 0xff ;
    temp= temp<<(32-d1-d2-d3-d4) | temp>>(d1+d2+d3+d4);
    K= temp>>16 ^ temp & 0xffff;
    printf("%hu",K);
    return 0;
}