#include <stdio.h>
#include<stdlib.h>

float firstNumber, secondNumber, result;

void calculation();

void print_binary(void *n)
{
    for (int k = 31; k >= 0; k--)
    {
        printf("%d", (*(int *)n >> k) & 1);
        if (k && !(k % 8))
            printf(" ");
    }
}

int main()
{
    calculation();
    return 0;
}
void calculation()
{
    scanf("%f %f", &firstNumber, &secondNumber);
    result = firstNumber + secondNumber;

    void *p1 = &firstNumber;
    void *p2 = &secondNumber;
    void *p3 = &result;
    printf("   ");
    print_binary((int *)p1);
    printf("\n+) ");
    print_binary((int *)p2);
    printf("\n---------------------------------------\n");
    printf("   ");

    for (int k = 31; k >= 0; k--)
    {
        printf("%d", (*(int *)p1 + *(int *)p2 >> k) & 1);
        if (k && !(k % 8))
            printf(" ");
    }
    printf("\n%d + %d = %d", (int)firstNumber, (int)firstNumber, (*(int *)p1 + *(int *)p2));
}