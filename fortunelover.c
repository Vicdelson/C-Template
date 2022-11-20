#include <stdio.h>
#include <stdlib.h>

float firstNumber, secondNumber, result;

void calculation();

void printBinary(void *n)
{
    // Prints the binary representation
    // of a number n up to k-bits.
    // to IEEE 754 floating point representation
    for (int k = 32; k > 0; k--) 
    {
        printf("%d", (*(int *)n >> k) & 1);
        if (k && !(k % 8))
        {
            printf(" ");
        }
    }
}
void calculation()
{
    scanf("%f %f", &firstNumber, &secondNumber);
    result = firstNumber + secondNumber;

    void *p1 = &firstNumber;
    void *p2 = &secondNumber;
    void *p3 = &result;

    printf("   ");
    printBinary((int *)p1);
    printf("\n");
    printf("+) ");
    printBinary((int *)p2);
    printf("\n");
    printf("---------------------------------------");
    printf("\n")
    printf("   ");

    for (int k = 32; k > 0; k--) 
    {
        printf("%d", (*(int *)p1 + *(int *)p2 >> k) & 1);
        if (k && !(k % 8))
        {
            printf(" ");
        }
    }
    printf("\n");
    /**result = *firstNumber + *secondNumber;
    int first = firstNumber;
    int second = secondNumber;
    int last = first + second;*/
    printf("%d + %d = %d", (int)firstNumber, (int)secondNumber, (*(int *)p1+ *(int *)p2));
}

int main()
{
    calculation();
    return 0;
}