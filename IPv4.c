#include<stdio.h>

int main(void)
{
    int value1, value2 , value3, value4;
    scanf("%2x%2x%2x%2x", &value1, &value2, &value3, &value4);
    printf("%d.%d.%d.%d", value1, value2, value3, value4);
}