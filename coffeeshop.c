#include <stdio.h>

int main(void)
{
    int i, j, price;
    scanf("%d %d", &i, &j);
    if (i <= 4)
    {
        switch (i)
        {
        case 1: price = 110 * j;
        printf("The total price is %d dollars!", price);
        break;
        case 2: price = 150 * j; 
        printf("The total price is %d dollars!", price);
        break;
        case 3: price = 135 * j;
        printf("The total price is %d dollars!", price);
        break;
        case 4: price = 145 * j;
        printf("The total price is %d dollars!", price);
        break;
        }
    }
    else
    {
        printf("Wait, what?");
    }
}
