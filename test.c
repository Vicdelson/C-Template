#include <stdio.h>
#include <stdlib.h>

float firstNumber, secondNumber, result;

/*typedef union 
{ 
    float firstNumber, secondNumber, result;
    struct
};*/

// Function to convert real value
// to IEEE floating point representation
void addition()
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
    printf("\n");
    printf("   ");

    for (int k = 31; k >= 0; k--)
    {
        printf("%d", (*(int *)p1 + *(int *)p2 >> k) & 1);
        if (k && !(k % 8))
        {
            printf(" ");
        }
    }
    printf("\n");
     /**result = *firstNumber + *secondNumber;*/
    int first = firstNumber;
    int second = secondNumber;
    int last = first + second;*/
    //int last = (*(int *)p1 + *(int *)p2);
    //printf("%d",last);
    printf("%d + %d = %d", first, second, (*(int *)p1 + *(int *)p2));
}

void printBinary(void *n)
{
    // Prints the binary representation
    // of a number n up to k-bits.
    // to IEEE 754 floating point representation
    for (int k = 31; k >= 0; k--)
    {
        printf("%d", (*(int *)n >> k) & 1);
        if (k && !(k % 8))
        {
            printf(" ");
        }
    }
     // Prints the binary representation
    // of a number n up to i-bits.
    /*int k;
    for (k = i - 1; k >= 0; k--) {
 
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }*/
}
// Driver Code
int main()
{
    addition();
    return 0;
}