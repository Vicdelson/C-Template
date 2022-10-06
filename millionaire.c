#include<stdio.h>

int main(void)
{
    float x,y,hidden_h,t,h,
    a=0.9,b=0.1,c=-51,d=-0.98,e=153;
    scanf("%f", &x);
    y=x;
    hidden_h = 0;
    for(t=0;t<5;++t)
    {
        h=(a*y)+(b*hidden_h)+c;
        y=(d*h)+e;
        printf("%.1f ",y);
        hidden_h = h;
    }
}