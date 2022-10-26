#include <stdio.h>


int main(){
    unsigned int tempo = 0, N;
    int d1, d2, d3, d4;
    unsigned int byte[5];


    //Split N into bytes of 4
    
    //Temp bytes 
    unsigned int temp[4];

    //Step 1:
    scanf("%u ", &N);
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
    

    byte[1] = (N &0xff000000) >> 24;
    byte[2] = (N & 0x00ff0000) >> 16;
    byte[3] = (N & 0x0000ff00) >> 8;
    byte[4] = (N & 0x000000ff);
    //Step 2: XOR d1'th byte of temp and d2'th byte of temp and store at 1st byte of temp
    temp[0] = byte[d1] ^ byte[d2];

    //Step 3: And the d2'th byte of N with the d3'th byte of N and store the result at the 2nd byte of temp
    temp[1] = byte[d2] & byte[d3];

    //Step 4: Or the d3'rd byte of N with the d1'th byte and store the result at the 3rd byte of temp
    temp[2] = byte[d3] | byte[d1];

    //Step 5: Toggle the d4'th byte of N and store the result at the 4th byte of temp (Convert 0 to 1 and vice versa)
    temp[3] = byte[d4] ^ 255;

    //Step 6: Rotate by d1+d2+d3+d4 bits to the right
    
    //First combine the 4 8-bit numbers into a 32 bit number
    tempo = (temp[0] << 24) | (temp[1] << 16) | (temp[2] << 8) | temp[3];
    int shift = d1 + d2 + d3 + d4;
    tempo = (tempo >> shift) | (tempo << (32 - shift));

    //Step 7: 
    byte[1] = (tempo &0xff000000) >> 24;
    byte[2] = (tempo & 0x00ff0000) >> 16;
    byte[3] = (tempo & 0x0000ff00) >> 8;
    byte[4] = (tempo & 0x000000ff);
    unsigned short temp_upper = (byte[1] << 8) | byte[2];
    unsigned short temp_lower = (byte[3] << 8) | byte[4];
    tempo = temp_upper ^ temp_lower;

    printf("%u", tempo);
}