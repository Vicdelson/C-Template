#include<stdio.h>

int main(void)
{
    int a,b,c,d;
    int i,j,k,l;
    int w,x,y,z;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    scanf("%d %d %d %d", &i, &j, &k, &l);
    scanf("%d %d %d %d", &w, &x, &y, &z);
    int sum1 = (a+b)*(c-d);
    int sum2 = (i+j)*(k-l);
    int sum3 = (w+x)*(y-z);
    printf("%d %d %d",sum1, sum2, sum3);
    return 0;
}