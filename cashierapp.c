#include <stdio.h>
#define array 50

int main()
{
    //skip part input item
    printf("Input item's name [5..30 characters] : ");
    printf("\n");
    //harga item
    printf("Input item's price[use decimal numbers | 10.0 - 2000]: $");
    float itemPrice[array];
    for(int i=0;i<array;)
    {
        scanf("%f", &itemPrice[i]);
        while(itemPrice[i]<10.0)
        {
            scanf("%f", &itemPrice[i]);
        }
        while(itemPrice[i]>2000.0)
        {
            scanf("%f", &itemPrice[i]);
        }
        while(itemPrice[i]<"0")
        {
            printf("Input must be number!");
            scanf("%f", &itemPrice[i]);
        }
        while(itemPrice[i]>"9")
        {
            printf("Input must be number!");
            scanf("%f", &itemPrice[i]);
        }
        printf("Input item's name [5..30 characters] : $", itemPrice[i]);
    }
    
}