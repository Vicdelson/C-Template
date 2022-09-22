#include <stdio.h>
#include <math.h>
int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7,i8, i9, i10, i11, i12,
    a,b,x,y,z;
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", 
    &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);
    a = (i2+i4+i6+i8+i10+i12);
    b = (i1+i3+i5+i7+i9+i11);
    x = ((a*3)+b);
    y = (x-1);
    printf("%d", 9-(y%10));
    return 0;
}