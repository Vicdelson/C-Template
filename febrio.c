#include <stdio.h>

void Ask(int n);

int total = 0;

int main()
{
    for(int n = 1; n <= 3; n++)
    {
        Ask(n);
    }
}
void Ask(int n)
{
    printf("Enter positive integer %d: ", n);
    int num;
    scanf("%d", &num);
    while(num<=0)
    {
        printf("Positive integers only, please\n");
        printf("Enter positive integer %d:", n);
        scanf("%d", &num);
    }
    total += num;
    if(n==3)
    {
        printf("Total= %d", total);
    }
}